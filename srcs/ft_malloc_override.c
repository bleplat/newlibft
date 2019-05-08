/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_override.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:09:05 by bleplat           #+#    #+#             */
/*   Updated: 2019/05/08 11:47:37 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdlib.h>
#include <unistd.h>

#include "libft_malloc_override.h"

/*
** ft_malloc_override.c
**
** Those functions are used to make malloc fail on purpose.
** This can be used to trigger memory leaks.
** Use without moderation.
**
** This file does not depend on the libft, for the folowing reasons:
** - do not waste my libft performances
** - test leaks on my libft
** - be easy and fast to use in a random project even if not mine
**
** The folowing env variables may be used:
** - FTMO_MODE: see ftmo_mode() function.
** - FTMO_COUNT: see ftmo_count() function.
** - FTMO: string of 0 (malloc) and 1 (fail), see ftmo_mode() function.
**
** Recommended FTMO_MODE=14: use FTMO to know when to fail, after FTMO_COUNT
** calls to malloc, then use malloc when no data available in FTMO
**
** See functions comments below.
*/

/*
** ftmo_count:
**
** Set a count or decrease the current by one.
** This is used by malloc logic, like "how many success/failure are requiered".
** It returns its last count, updating it, or decreasing it by 1.
** Possible values:
** FTMO_COUNT_INFINITE: count will be set to high and not decrease.
** <positive_integer>: countset to 'new_count', and decrease by one every call
** FTMO_COUNT_RETRIEVE: trigger the next count and return the current one.
** FTMO_COUNT_GET: get what should be the next count without triggering anything.
*/

int			ftmo_count(int new_count)
{
	static int		count = FTMO_COUNT_INFINITE;
	int				rst;

	rst = count;
	if (rst != FTMO_COUNT_INFINITE && new_count != FTMO_COUNT_GET)
		count -= 1;
	if (new_count != FTMO_COUNT_RETRIEVE && new_count != FTMO_COUNT_GET)
		count = new_count;
	return (rst);
}

int			ftmo_init(void)
{
	char	*rst;
	int		mode;

	rst = getenv("FTMO_COUNT");
	if (rst)
		ftmo_count(atoi(rst));
	mode = (FTMO_MODE_MALLOC | FTMO_MODE_RESET);
	rst = getenv("FTMO_MODE");
	if (rst)
		mode = atoi(rst);
	return (mode);
}

static void	ftmo_ftmo(int *rst, int cnt, int mode)
{
	char	*ftmo;
	int		len;

	if (cnt <= 0)
	{
		ftmo = getenv("FTMO");
		if (ftmo != NULL)
		{
			len = 0;
			while (ftmo[len])
				len++;
			if ((-cnt) < len)
				(*rst) = (ftmo[-cnt] == '0') ? 0 : 1;
			else if (!(mode & FTMO_MODE_RESET))
				(*rst) = 1 - (*rst);
		}
	}
}

/*
** ftmo_mode:
**
** Define the behavior of malloc, according to 'mode' (or's them together):
** - FTMO_MODE_MALLOC (2/0): default behavior is to call malloc.
** - FTMO_MODE_FAIL (1): default behavior is to fail.
** - FTMO_MODE_RESET (4): once the count reached, go back to default
** - FTMO_MODE_ENV (8): use env variable 'FTMO' to decide when to succeed
** or fail.
** - FTMO_MODE_TRIGGER: get if malloc should succeed and trigger next.
*/

int			ftmo_mode(int new_mode)
{
	static int			mode = FTMO_MODE_INIT;
	int					rst;
	int					cnt;

	if (mode == FTMO_MODE_INIT)
		mode = ftmo_init();
	if (mode & FTMO_MODE_FAIL)
		rst = 1;
	else
		rst = 0;
	cnt = ftmo_count(FTMO_COUNT_RETRIEVE);
	if (mode & FTMO_MODE_ENV)
		ftmo_ftmo(&rst, cnt, mode);
	else if (cnt == 0 || (!(mode & FTMO_MODE_RESET) && cnt < 0))
		rst = 1 - rst;
	if (new_mode != FTMO_MODE_TRIGGER)
		mode = new_mode;
	return (rst);
}

/*
** malloc:
**
** Overload the malloc function in the libc.
*/

void		*malloc(size_t sz)
{
	void	*(*libc_malloc)(size_t);

	if (ftmo_mode(FTMO_MODE_TRIGGER))
	{
		write(0, "MALLOC FAILED\n", 14);
		return (NULL);
	}
	libc_malloc = dlsym(RTLD_NEXT, "malloc");
	return (libc_malloc(sz));
}
