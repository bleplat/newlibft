/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_onerstpart_bracket.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:09:21 by bleplat           #+#    #+#             */
/*   Updated: 2019/02/27 20:23:19 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

int			ft_printf_nextrstpart_bracket(
					char **next_fmt, char *fmt, t_printf_rstpart *part)
{
	char		*start;

	start = fmt;
	*next_fmt = ft_strchr(fmt, '}');
	if (*next_fmt == NULL)
		part->str = ft_strdup(start - 1);
	else
		part->str = ft_hcolortoansi(start);
	if (part->str == NULL)
		return (-1);
	if (*next_fmt == NULL)
		*next_fmt = ft_strchr(start, '\0');
	else
		*next_fmt += 1;
	return (0);
}
