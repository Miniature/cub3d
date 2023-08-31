/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:54:30 by wdavey            #+#    #+#             */
/*   Updated: 2023/08/31 11:22:45 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>
# include <stddef.h>

typedef struct s_pos {
	size_t	x;
	size_t	y;
}	t_pos;

t_pos	pos_new(size_t x, size_t y);
bool	pos_equal(t_pos a, t_pos b);

int		error(char *msg);

#endif
