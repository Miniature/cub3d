/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:54:30 by wdavey            #+#    #+#             */
/*   Updated: 2024/03/20 19:47:16 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>
# include <stddef.h>

typedef struct s_pos
{
	float	x;
	float	y;
}	t_pos;

t_pos	pos_new(float x, float y);
bool	pos_equal(t_pos a, t_pos b);
bool	pos_near(t_pos a, t_pos b, float max_distance);
t_pos	pos_add(t_pos a, t_pos b);
t_pos	pos_rotate(t_pos pos, float angle);
t_pos	pos_mult(t_pos pos, float factor);

int		error(char *msg);

#endif
