/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:09:28 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/16 13:28:40 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "libft_array.h"

/*
** Delete an ft_array and set the pointer to NULL.
*/

void		ft_array_del(t_array **a)
{
	free((*a)->items);
	free((*a));
	(*a) = NULL;
}

int			ft_array_del0(t_array **a)
{
	ft_array_del(a);
	return (0);
}
