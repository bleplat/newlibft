/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:55:29 by bleplat           #+#    #+#             */
/*   Updated: 2018/12/14 15:57:44 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_intsize(int i)
{
	int		size;

	size = 0;
	if (i < 0)
		size++;
	while (i > 9 || i < -9)
	{
		i /= 10;
		size++;
	}
	size++;
	return (size);
}
