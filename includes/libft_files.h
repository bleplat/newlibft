/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_files.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 04:17:22 by bleplat           #+#    #+#             */
/*   Updated: 2019/04/01 07:00:30 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_FILES_H
# define LIBFT_FILES_H

#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>

/*
** H e l p e r s
*/

char		*ft_strmode(mode_t mode);
char		*ft_dirfilepath(char *dir, char *file);

/*
** F i l e s
*/

mode_t		ft_filemode(const char *filename);

/*
** D i r e c t o r i e s
*/

int			ft_listdir(char ***out, const char *dir);

#endif
