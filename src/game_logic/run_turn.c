/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_turn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:01:32 by wdavey            #+#    #+#             */
/*   Updated: 2023/08/31 17:22:39 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_printf.h"
#include "mlx.h"

#include "mlxw.h"
#include "gamestate.h"
#include "keycodes.h"

typedef struct s_gamewindow {
	t_mlx_window	win;
	t_gamestate		game;
}	t_gamewindow;

void	patrol_move(t_entity *patrol);
void	player_move(t_entity *player, t_pos move);

t_pos	keycode_to_movement(int keycode)
{
	t_pos	mov;

	mov = pos_new(0, 0);
	if (KEY_A == keycode || KEY_LEFT == keycode)
		mov = pos_new(-1, 0);
	if (KEY_S == keycode || KEY_DOWN == keycode)
		mov = pos_new(0, 1);
	if (KEY_D == keycode || KEY_RIGHT == keycode)
		mov = pos_new(1, 0);
	if (KEY_W == keycode || KEY_UP == keycode)
		mov = pos_new(0, -1);
	return (mov);
}

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

static int	close(t_gamewindow *gw)
{
	gamestate_destroy(gw->game, gw->win);
	exit(0);
	return (0);
}

int	run_turn(int keycode, t_gamewindow *gw)
{
	t_pos	mov;
	t_pos	player_pos;

	mov = keycode_to_movement(keycode);
	player_pos = gw->game.entities.player->pos;
	if (!pos_equal(pos_new(0, 0), keycode_to_movement(keycode)))
	{
		if (WALL_CHAR != gw->game.map.raw[pos_add(player_pos, mov).y]
			[pos_add(player_pos, mov).x])
		{
			player_move(gw->game.entities.player, keycode_to_movement(keycode));
			ft_lstiter(gw->game.entities.patrols,
				(void (*)(void *))patrol_move);
		}
		if (handle_collisions(&(gw->game)))
		{
			if (NULL == gw->game.entities.collectibles)
				ft_printf("you win\n");
			else
				ft_printf("you lose\n");
			close(gw);
		}
	}
	gamestate_render(gw->game, gw->win);
	return (0);
}
