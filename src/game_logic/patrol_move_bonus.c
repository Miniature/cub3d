/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol_move_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:00:14 by wdavey            #+#    #+#             */
/*   Updated: 2024/02/01 14:33:05 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>

#include "entity.h"
#include "slmap.h"
#include "gamestate.h"

static t_pos	dir_to_pos(enum e_patrol_dir dir)
{
	if (NORTH == dir)
		return (pos_new(0, -1));
	if (SOUTH == dir)
		return (pos_new(0, 1));
	if (WEST == dir)
		return (pos_new(-1, 0));
	if (EAST == dir)
		return (pos_new(1, 0));
	return (pos_new(0, 0));
}

//rand sucks but it is good enough for this
void	patrol_move(t_entity *patrol, t_slmap map)
{
	t_pos	nextpos;

	nextpos = pos_add(patrol->pos, dir_to_pos(patrol->data));
	if (WALL_CHAR != map.raw[(int)round(nextpos.y)][(int)round(nextpos.x)])
	{
		patrol->pos = nextpos;
	}
	patrol->data = rand() % 4;
}

void	move_patrols(t_gamewindow *gw)
{
	t_list	*patrols;

	patrols = gw->game.entities.patrols;
	while (NULL != patrols)
	{
		patrol_move(patrols->content, gw->game.map);
		patrols = patrols->next;
	}
}
