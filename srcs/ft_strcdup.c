/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 18:45:46 by jthierce          #+#    #+#             */
/*   Updated: 2020/06/15 18:45:46 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcdup(const char *s1, char c)
{
	char	*new_str;
	size_t	len;
	size_t	i;
	int		size_malloc;

	len = ft_strlen(s1);
	size_malloc = ft_strclen(s1, c);
	new_str = ft_strnew(size_malloc + 1);
	if (new_str != NULL)
	{
		i = 0;
		while (i < len && s1[i] != c)
		{
			new_str[i] = s1[i];
			i++;
		}
	}
	return (new_str);
}
