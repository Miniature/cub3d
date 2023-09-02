/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamestate_render.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 09:51:22 by wdavey            #+#    #+#             */
/*   Updated: 2023/09/02 13:14:50 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "gamestate.h"
#include "entity.h"
#include "sprite.h"

#ifdef GAMESTATE_USE_TERRAIN_IMAGE

void	gamestate_render_terrain(t_gamestate state, t_mlx_window win)
{
	mlxw_draw(win, state.terrain, pos_new(0, 0));
}
#else

void	gamestate_render_terrain(t_gamestate state, t_mlx_window win)
{
	t_pos	i;

	i.y = 0;
	while ((unsigned)i.y < state.map.height)
	{
		i.x = 0;
		while ((unsigned)i.x < state.map.width)
		{
			if (WALL_CHAR == state.map.raw[i.y][i.x])
				sprite_draw(state.terrain_sprites.wall, win, i);
			else
				sprite_draw(state.terrain_sprites.floor, win, i);
			i.x++;
		}
		i.y++;
	}
}
#endif

void	gamestate_render(t_gamestate state, t_mlx_window win)
{
	t_list		*entity_list;
	t_entity	*entity;

	gamestate_render_terrain(state, win);
	entity_list = state.entities.collectibles;
	while (NULL != entity_list)
	{
		entity = ((t_entity *)(entity_list->content));
		entity_draw(*entity, win);
		entity_list = entity_list->next;
	}
	entity_list = state.entities.patrols;
	while (NULL != entity_list)
	{
		entity = ((t_entity *)(entity_list->content));
		entity_draw(*entity, win);
		entity_list = entity_list->next;
	}
	entity_draw(*state.entities.exit, win);
	entity_draw(*state.entities.player, win);
}
