/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ints_demo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:46:37 by bleplat           #+#    #+#             */
/*   Updated: 2019/03/05 16:59:26 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				main(int argc, char **argv)
{
	int		min;
	int		count;
	int		step;
	int		*ints;

	if (argc < 3)
		return (1);
	min = ft_atoi(argv[1]);
	count = ft_atoi(argv[2]);
	step = (argc > 3) ? ft_atoi(argv[3]) : 1;
	if (!(ints = ft_intsrange(min, count, step)))
		return (2);
	if ((argc > 4) && argv[4][0] == '1')
		ft_intsshuffle(ints, count);
	ft_putints(ints, count, (argc > 5) ? argv[5] : " ");
	return (0);
}
