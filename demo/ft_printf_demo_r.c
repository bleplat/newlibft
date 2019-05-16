/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_demo_r.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 20:06:16 by bleplat           #+#    #+#             */
/*   Updated: 2019/05/16 20:06:21 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int				main(void)
{
	static char		*data = "Some \x01\x02hAArdd \x9f coded\x82 non-asc\xd1ii";

	ft_printf("With %%s:  \"%s\"\n", data);
	ft_printf("With %%r:  \"%r\"\n", data);
	ft_printf("With %%#r: \"%#r\"\n", data);
	return (0);
}
