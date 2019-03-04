/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_n.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 19:53:42 by bleplat           #+#    #+#             */
/*   Updated: 2019/02/27 21:59:10 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

/*
** Output the number 'cnt' to integer pointed by the address contained in ap.
** conv is used to check the output size.
*/

int		ft_printf_format_n(t_printf_rstpart *part, va_list ap, int cnt)
{
	void	*dst;
	int		conv;

	conv = part->fmt->conversion;
	dst = ft_va_as_ptr(ap);
	if (conv & FT_PRINTF_LENMOD_CHAR)
		*((signed char*)dst) = cnt;
	else if (conv & FT_PRINTF_LENMOD_SHORT)
		*((short*)dst) = cnt;
	else if (conv & FT_PRINTF_LENMOD_LONG)
		*((long int*)dst) = cnt;
	else if (conv & FT_PRINTF_LENMOD_LONGLONG)
		*((long long int*)dst) = cnt;
	else if (conv & FT_PRINTF_LENMOD_INTMAX)
		*((ptrdiff_t*)dst) = cnt;
	else if (conv & FT_PRINTF_LENMOD_PTRDIFF)
		*((intmax_t*)dst) = cnt;
	else if (conv & FT_PRINTF_LENMOD_SIZE)
		*((size_t*)dst) = cnt;
	else
		*((int*)dst) = cnt;
	ft_memdel((void**)&part->fmt);
	return (0);
}
