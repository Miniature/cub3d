/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_turn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:01:32 by wdavey            #+#    #+#             */
/*   Updated: 2024/03/04 17:42:34 by wdavey           ###   ########.fr       */
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
		if (pos_near(state->entities.player->pos,
				((t_entity *)(*entity)->content)->pos, 0.2f))
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
		if (pos_near(state->entities.player->pos,
				((t_entity *)(entity->content))->pos, 0.2f))
			return (true);
		entity = entity->next;
	}
	//if (pos_near(state->entities.player->pos, state->entities.exit->pos, 0.2f)
	//	&& NULL == state->entities.collectibles)
	//	return (true);
	return (false);
}

int	run_turn(t_gamewindow *gw)
{
	if (handle_collisions(&(gw->game)))
		;
	return (gamestate_render(gw));
}
