/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_removeat.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 14:04:50 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/29 16:56:07 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Remove the last item in an array and return a pointer
** to where it was stored.
**
** The memory is not freed by this function, so it remain available until you
** use another function on the list.
**
** UNTESTED!!!
*/

void						*ft_array_pop(t_array *a)
{
	if (a->item_count == 0)
		return (NULL);
	a->item_count--;
	return (a->items + a->item_size * a->item_count);
}

int							ft_array_pop0(t_array *a)
{
	if (a->item_count == 0)
		return (0);
	a->item_count--;
	return (0);
}
