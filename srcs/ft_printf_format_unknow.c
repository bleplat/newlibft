/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_unknow.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:13:15 by bleplat           #+#    #+#             */
/*   Updated: 2019/02/27 20:21:04 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

/*
** See ft_printf_format()
*/

int			ft_printf_format_unknow(t_printf_rstpart *part, va_list ap)
{
	(void)ap;
	if (!(part->str = ft_strnew(1)))
		return (-1);
	if (part->fmt->options & FT_PRINTF_OPTION_UPPER)
		part->str[0] = ft_toupper((char)part->fmt->conversion);
	else
		part->str[0] = (char)part->fmt->conversion;
	return (0);
}
