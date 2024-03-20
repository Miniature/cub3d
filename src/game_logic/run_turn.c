/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_turn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:01:32 by wdavey            #+#    #+#             */
/*   Updated: 2024/03/20 21:03:55 by wdavey           ###   ########.fr       */
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
	return (false);
}

int	run_turn(t_gamewindow *gw)
{
	int	mouse_pos[2];

	if (handle_collisions(&(gw->game)))
		;
	if (gw->using_mouse)
	{
		mlx_mouse_get_pos(gw->win.win, mouse_pos, mouse_pos + 1);
		gw->game.entities.player->facing -= mouse_pos[0] * MOUSE_TURN_SPEED;
		mlx_mouse_move(gw->win.win, 0, 0);
	}
	return (gamestate_render(gw));
}
