/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamestate_render_minimap.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:24:10 by wdavey            #+#    #+#             */
/*   Updated: 2024/03/20 21:27:22 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "mlxw.h"
#include "gamestate.h"

static void	minimap_snapshot(t_gamewindow *gw, t_mlx_image minimap)
{
	int			iii;
	int			jjj;
	t_pos		tile_pos;

	iii = -1;
	while (++iii < 6)
	{
		jjj = -1;
		while (++jjj < 6)
		{
			tile_pos = pos_add(gw->game.entities.player->pos,
					pos_new(iii - 2, jjj - 2));
			if (slmap_get_block(gw->game.map, tile_pos.y, tile_pos.x)
				== FLOOR_CHAR)
				mlxw_image_overlay(minimap,
					gw->game.terrain_sprites.floor.frames[0],
					pos_mult(pos_new(iii, jjj), 32));
			else
				mlxw_image_overlay(minimap,
					gw->game.terrain_sprites.wall.frames[0],
					pos_mult(pos_new(iii, jjj), 32));
		}
	}
}

static t_mlx_image	current_player_image(t_gamewindow *gw)
{
	static size_t	frame_count;
	t_sprite		*sprite;
	size_t			cycle_frames;
	size_t			iii;

	sprite = gw->game.entities.player->sprite;
	iii = -1;
	cycle_frames = 0;
	while (++iii < sprite->frame_count)
	{
		cycle_frames += sprite->frame_dur[iii];
		if (frame_count < cycle_frames)
		{
			frame_count++;
			return (sprite->frames[iii]);
		}
	}
	frame_count = 0;
	return (sprite->frames[0]);
}

void	gamestate_render_minimap(t_gamewindow *gw)
{
	t_mlx_image	minimap;
	t_pos		player_pos;

	player_pos = (t_pos){(gw->game.entities.player->pos.x * 32 - (32 * 2)),
		(gw->game.entities.player->pos.y * 32 - (32 * 2))};
	minimap = mlxw_new_image(gw->win.mlx,
			gw->game.terrain_sprites.floor.frames[0].w * 12,
			gw->game.terrain_sprites.floor.frames[0].h * 6);
	minimap_snapshot(gw, minimap);
	mlxw_image_overlay(minimap, current_player_image(gw),
		pos_new(64 + fmod(gw->game.entities.player->pos.x, 1) * 32,
			56 + fmod(gw->game.entities.player->pos.y, 1) * 32));
	mlxw_image_overlay(gw->game.raycast_img, minimap, pos_new(0, 0));
	mlxw_destroy_image(minimap, gw->win.mlx);
}
