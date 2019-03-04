/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_welcome.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 13:29:02 by bleplat           #+#    #+#             */
/*   Updated: 2019/03/04 13:46:12 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_welcome(void)
{
	int		foreground;
	int		background;

	foreground = (ft_urandom() + 256) % 256;
	background = (ft_urandom() + 256) % 256;
	ft_printf("%y%#yWelcome!{}\n", foreground, background);
	return (0);
}
