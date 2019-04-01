/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdir_demo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 04:25:28 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/01 04:58:16 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>

#include "libft.h"

int			main(int argc, char **argv)
{
	char		**dir_names;

	if (argc != 2)
	{
		ft_printf("usage: %s directory\n", argv[0]);
		return (127);
	}
	if (ft_listdir(&dir_names, argv[1]) < 0)
	{
		perror(argv[0]);
		return (errno);
	}
	ft_putstrvec((const char**)dir_names, -1, "\n");
	ft_putchar('\n');
	ft_vecdel((void**)&dir_names, 1);
	return (0);
}
