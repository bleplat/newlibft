/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linkfolow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 09:46:47 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/09 19:14:19 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <unistd.h>

#include "libft.h"

// TODO: fix the 2048 with a growing buffer!
char			*ft_linkfolow(const char *link)
{
	ssize_t		size;
	char		buf[2048 + 1];
	char		*cpy;

	if ((size = readlink(link, buf, 2048)) < 0)
		return (NULL);
	cpy = ft_strsub(buf, 0, size);
	if (!cpy)
		errno = ENOMEM;
	return (cpy);
}
