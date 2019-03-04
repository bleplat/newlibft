/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_y.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:15:39 by bleplat           #+#    #+#             */
/*   Updated: 2019/02/27 20:04:01 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

/*
** See ft_printf_format()
*/

int			ft_printf_format_y(t_printf_rstpart *part, va_list ap)
{
	int		color;
	int		flags;

	color = ft_printf_readva_uint(part->fmt->conversion, ap);
	flags = 0;
	if (part->fmt->options & FT_PRINTF_OPTION_UPPER)
		flags |= FT_ANSICOLOR_FLAG_RGB;
	if (part->fmt->options & FT_PRINTF_OPTION_ALT)
		flags |= FT_ANSICOLOR_FLAG_BACKGROUND;
	part->str = ft_ansicolor(color, flags);
	return ((part->str) ? 0 : -1);
}
