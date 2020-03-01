/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstrprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:02:25 by bleplat           #+#    #+#             */
/*   Updated: 2020/03/01 16:04:20 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return 1 if the string is entirely printable, 0 otherwise.
*/

int								ft_isstrprint(const char *str)
{
	while (*str)
	{
		if (!ft_isprint(*str))
			return (1);
		str++;
	}
	return (1);
}
