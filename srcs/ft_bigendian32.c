/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigendian32.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 19:05:46 by bleplat           #+#    #+#             */
/*   Updated: 2020/06/17 19:05:49 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

/*
** Read an int32 from a byte array encoded in big endian.
*/

int32_t			ft_bigendian32_read(unsigned char *data32)
{
	int32_t		total;

	total = 0;
	total |= (int32_t)data32[3] << 0;
	total |= (int32_t)data32[2] << 8;
	total |= (int32_t)data32[1] << 16;
	total |= (int32_t)data32[0] << 24;
	return (total);
}

/*
** Write an int32 to a byte array encoded in big endian.
*/

void			ft_bigendian32_write(unsigned char *data32, int32_t int32)
{
	data32[3] = (int32 >> 0) & 0xFF;
	data32[2] = (int32 >> 8) & 0xFF;
	data32[1] = (int32 >> 16) & 0xFF;
	data32[0] = (int32 >> 24) & 0xFF;
}
