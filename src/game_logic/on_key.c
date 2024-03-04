/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:28:57 by wdavey            #+#    #+#             */
/*   Updated: 2024/02/26 17:04:08 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>

#include "ft_printf.h"
#include "mlx.h"

#include "mlxw.h"
#include "gamestate.h"
#include "keycodes.h"

void	player_move(t_entity *player, t_pos move);
int		sl_close(t_gamewindow *gw);

#define MOVE_SPEED 0.1f
#define KEY_TURN_SPEED 0.261799f

t_pos	keycode_to_movement(int keycode)
{
	t_pos	mov;

	mov = pos_new(0, 0);
	if (KEY_A == keycode)
		mov = pos_new(-MOVE_SPEED, 0);
	if (KEY_S == keycode || KEY_DOWN == keycode)
		mov = pos_new(0, MOVE_SPEED);
	if (KEY_D == keycode)
		mov = pos_new(MOVE_SPEED, 0);
	if (KEY_W == keycode || KEY_UP == keycode)
		mov = pos_new(0, -MOVE_SPEED);
	return (mov);
}

float	keycode_to_rotation(int keycode)
{
	if (KEY_LEFT == keycode)
		return (KEY_TURN_SPEED);
	if (KEY_RIGHT == keycode)
		return (-KEY_TURN_SPEED);
	return (0.0f);
}

static bool	is_valid_move(t_slmap map, t_pos start, t_pos end)
{
	if (round(start.x) != round(end.x) && round(start.y) != round(end.x))
	{
		if (WALL_CHAR
			== slmap_get_block(map, (int)round(start.y), (int)round(end.x))
			&& WALL_CHAR
			== slmap_get_block(map, (int)round(start.x), (int)round(end.y)))
			return (false);
	}
	return (WALL_CHAR != slmap_get_block(map, round(end.y), round(end.x)));
}

int	on_key(int keycode, t_gamewindow *gw)
{
	t_pos	mov;
	t_pos	player_pos;

	if (KEY_ESC == keycode)
		sl_close(gw);
	if (0.0f != keycode_to_rotation(keycode))
		gw->game.entities.player->facing += keycode_to_rotation(keycode);
	mov = keycode_to_movement(keycode);
	if (!pos_equal(pos_new(0, 0), mov))
	{
		player_pos = gw->game.entities.player->pos;
		if (is_valid_move(gw->game.map, player_pos,
				pos_add(player_pos, pos_rotate(keycode_to_movement(keycode),
						gw->game.entities.player->facing))))
		{
			player_move(gw->game.entities.player,
				pos_rotate(keycode_to_movement(keycode),
					gw->game.entities.player->facing));
		}
	}
	return (0);
}
