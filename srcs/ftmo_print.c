/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmo_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 23:43:22 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/14 03:53:47 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libftmo.h"

static void	begin(int fd, int v)
{
	if (v == FTMO_INFO)
		ft_putstr_fd("\e[94mFTMO: \e[32mINFO: \e[92m", fd);
	if (v == FTMO_WARN)
		ft_putstr_fd("\e[94mFTMO: \e[33mWARNING: \e[93m", fd);
	if (v == FTMO_ERROR)
		ft_putstr_fd("\e[94mFTMO: \e[31mERROR: \e[91m", fd);
}

int			ftmo_log(int v, const char *msg)
{
	int fd;

	if ((fd = ftmo_getenv_logd(v)) < 0)
		return (v);
	begin(fd, v);
	ft_putstr_fd(msg, fd);
	ft_putstr_fd("\n", fd);
	return (v);
}

int			ftmo_putreg(int fd, t_ftmo_region *r)
{
	ft_putstr_fd("[", fd);
	ft_putnbr_fd(r->index, fd);
	ft_putstr_fd(" -- addr: 0x", fd);
	ft_putxnbr_fd((unsigned long long)r->ptr, fd);
	ft_putstr_fd(" size: ", fd);
	ft_putnbr_fd(r->size, fd);
	ft_putstr_fd("]", fd);
	return (0);
}

int			ftmo_log_p(int v, const char *p, void *pt, const char *s)
{
	t_ftmo_region r;

	r.index = -1;
	r.size = 0;
	r.ptr = pt;
	return (ftmo_log_r(v, p, &r, s));
}

int			ftmo_log_r(int v, const char *p, t_ftmo_region *r, const char *s)
{
	int			fd;

	if ((fd = ftmo_getenv_logd(v)) < 0)
		return (v);
	begin(fd, v);
	ft_putstr_fd(p, fd);
	ftmo_putreg(fd, r);
	ft_putstr_fd(s, fd);
	ft_putstr_fd("\n", fd);
	return (v);
}
