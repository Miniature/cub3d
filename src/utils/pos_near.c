/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_near.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:55:12 by wdavey            #+#    #+#             */
/*   Updated: 2024/02/26 15:57:52 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#include <stdbool.h>
#include <math.h>

bool	pos_near(t_pos a, t_pos b, float max_distance)
{
	return (pow(fabs(a.x - b.x), 2) + pow(fabs(a.y - b.y), 2)
		< pow(max_distance, 2));
}
