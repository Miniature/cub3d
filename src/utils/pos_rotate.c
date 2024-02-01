/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:44:13 by wdavey            #+#    #+#             */
/*   Updated: 2024/02/01 15:49:28 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <math.h>

#include "utils.h"

t_pos	pos_rotate(t_pos pos, float angle)
{
	return ((t_pos){
		pos.x * cos(angle) + pos.y * sin(angle),
		pos.y * cos(angle) + pos.x * sin(angle)
	});
}
