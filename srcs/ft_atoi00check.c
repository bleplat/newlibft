/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi00check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 22:04:51 by bleplat           #+#    #+#             */
/*   Updated: 2020/06/18 06:11:50 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_atoi00check_p2(int *out, long long total)
{
	(*out) = (int)total;
	return (0);
}

/*
** Same as ft_atoi00check() but count a char as a valid end of integer.
*/

int			ft_atoi00checkc(int *out, const char *str, char end)
{
	int				i;
	long long		sign;
	long long		total;

	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = (str[i] == '-') ? -1 : 1;
		i++;
	}
	total = 0;
	if (str[i] == '\0' || str[i] == end || !ft_isdigit(str[i]))
		return (-1);
	while (str[i] != end)
	{
		if (!ft_isdigit(str[i]))
			break ;
		total = (total * 10) + (str[i] - '0');
		i++;
	}
	return (ft_atoi00check_p2(out, total * sign));
}

/*
** Read an int as ft_atoi, but return 0 on success, and a negative value if the
** string is not a valid int.
** Return -1 on invalid character.
** This version doesnt check integer limits.
** This version only perform basi tests on the begining of the chain.
*/

int			ft_atoi00check(int *out, const char *str)
{
	return (ft_atoi00checkc(out, str, '\0'));
}
