/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_malloc_override.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:36:00 by bleplat           #+#    #+#             */
/*   Updated: 2019/05/08 10:41:13 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MALLOC_OVERRIDE_H
# define LIBFT_MALLOC_OVERRIDE_H

# define FTMO_COUNT_INFINITE 2147483647
# define FTMO_INFINITE FTMO_COUNT_INFINITE
# define FTMO_COUNT_RETRIEVE -2147483648
# define FTMO_COUNT_GET -2147483647
# define FTMO_CR FTMO_COUNT_RETRIEVE

# define FTMO_MODE_INIT 0x0
# define FTMO_MODE_MALLOC 0x2
# define FTMO_MODE_FAIL 0x1
# define FTMO_MODE_RESET 0x4
# define FTMO_MODE_ENV 0x8
# define FTMO_MODE_TRIGGER 0x0

int			ftmo_mode(int mode);

#endif
