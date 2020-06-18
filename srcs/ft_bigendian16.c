/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigendian16.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 19:05:38 by bleplat           #+#    #+#             */
/*   Updated: 2020/06/17 19:05:40 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

/*
** Read an int16 from a byte array encoded in big endian.
*/

int16_t			ft_bigendian16_read(unsigned char *data16)
{
	int16_t		total;

	total = 0;
	total |= (int16_t)data16[1] << 0;
	total |= (int16_t)data16[0] << 8;
	return (total);
}

/*
** Write an int16 to a byte array encoded in big endian.
*/

void			ft_bigendian16_write(unsigned char *data16, int16_t int16)
{
	data16[1] = (int16 >> 0) & 0xFF;
	data16[0] = (int16 >> 8) & 0xFF;
}
