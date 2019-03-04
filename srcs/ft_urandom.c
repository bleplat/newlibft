/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_urandom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:55:05 by bleplat           #+#    #+#             */
/*   Updated: 2018/12/05 15:17:03 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

unsigned int		ft_urandom(void)
{
	int		rst;

	rst = ft_random();
	return ((unsigned int)((rst > 0) ? rst : -rst));
}
