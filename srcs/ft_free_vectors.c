/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_vectors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:57:54 by bleplat           #+#    #+#             */
/*   Updated: 2018/12/07 17:15:44 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

/*
** Free arrays of pointers, that could themself be arrays of pointers, they will
** be freed recursively.
** Take as parameter a pointer to free.
** If layers > 1 then to_free is considered to be an array and each element will
** be freed by another call to the function.
*/

void		ft_free_vectors(void *to_free, int layers)
{
	int		i;
	void	**subs;

	if (layers > 1)
	{
		subs = (void **)to_free;
		i = 0;
		while (subs[i] != NULL)
		{
			ft_free_vectors(subs[i], layers - 1);
			i++;
		}
	}
	free(to_free);
}
