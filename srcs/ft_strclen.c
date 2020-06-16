/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:55:55 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/15 19:29:28 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isseparator(char c, char separator)
{
	return (c == separator);
}

/*
** Computes and returns the length of the string s until separator c.
*/

size_t			ft_strclen(const char *s, char c)
{
	size_t		i;

	i = 0;
	while (s[i] != '\0' && !(ft_isseparator(s[i], c)))
		i++;
	return (i);
}
