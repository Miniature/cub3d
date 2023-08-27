/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:47:53 by wdavey            #+#    #+#             */
/*   Updated: 2023/08/23 06:10:14 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FLAGS_H
# define FT_PRINTF_FLAGS_H

# include <stdbool.h>
# include <stddef.h>

//alt # also stores upper/lower internally to printf_hex
//left -
//sign +
//ssign  
//pad_0 0
//width <number>
//precision .<number>
typedef struct s_ft_printf_flags {
	char	alt;
	bool	left;
	bool	sign;
	bool	ssign;
	bool	pad_0;
	int		width;
	int		precision;
}	t_ft_printf_flags;

#endif
