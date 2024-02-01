/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_turn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:01:32 by wdavey            #+#    #+#             */
/*   Updated: 2024/02/01 15:30:35 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>

#include "ft_printf.h"
#include "mlx.h"

#include "mlxw.h"
#include "gamestate.h"
#include "keycodes.h"

void	patrol_move(t_entity *patrol);
void	player_move(t_entity *player, t_pos move);
void	move_patrols(t_gamewindow *gw);
int		sl_close(t_gamewindow *gw);

void	handle_collisions_collectibles(t_gamestate *state)
{
	t_list	**entity;
	t_list	*temp;

	entity = &(state->entities.collectibles);
	while (NULL != *entity)
	{
		if (pos_equal(state->entities.player->pos,
				((t_entity *)(*entity)->content)->pos))
		{
			free((*entity)->content);
			temp = *entity;
			*entity = (*entity)->next;
			free(temp);
		}
		else
			entity = &((*entity)->next);
	}
}

//returns true if the game should end
bool	handle_collisions(t_gamestate *state)
{
	t_list	*entity;

	handle_collisions_collectibles(state);
	entity = state->entities.patrols;
	while (NULL != entity)
	{
		if (pos_equal(state->entities.player->pos,
				((t_entity *)(entity->content))->pos))
			return (true);
		entity = entity->next;
	}
	if (pos_equal(state->entities.player->pos, state->entities.exit->pos)
		&& NULL == state->entities.collectibles)
		return (true);
	return (false);
}

int	run_turn(t_gamewindow *gw)
{
	return (gamestate_render(gw));
}
