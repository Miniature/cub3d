/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamestate_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:56:36 by wdavey            #+#    #+#             */
/*   Updated: 2023/09/02 13:10:04 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "gamestate.h"
#include "slmap.h"
#include "mlxw.h"

t_mlx_image				gamestate_init_terrain(t_mlx_window window,
							t_slmap map, char *rsc_path);
t_gamestate_entities	gamestate_init_entities(t_mlx_window window,
							t_slmap mapdata, char *rsc_path);

bool	gamestate_is_valid(t_gamestate state)
{
	t_pos	p;

	if (0 >= ft_lstsize(state.entities.collectibles))
		error("no collectibles on map");
	p = pos_new(0, 0);
	while (p.y < (signed)state.map.height)
	{
		while (p.x < (signed)state.map.width)
		{
			if (WALL_CHAR != state.map.raw[p.y][p.x])
				error("map is not entirely enclosed");
			p.x++;
		}
		p.y++;
	}
	return (true);
}

#ifdef GAMESTATE_USE_TERRAIN_IMAGE

t_gamestate	gamestate_init(t_mlx_window window, t_slmap mapdata, char *rsc_path)
{
	t_gamestate	state;

	state.terrain = gamestate_init_terrain(window, mapdata, rsc_path);
	state.entities = gamestate_init_entities(window, mapdata, rsc_path);
	state.map = mapdata;
	state.terrain_sprites.wall
		= sprite_load(window.mlx, rsc_path, "wall_fallback.xpm");
	state.terrain_sprites.floor
		= sprite_load(window.mlx, rsc_path, "floor.xpm");
	return (state);
}
#else

t_gamestate	gamestate_init(t_mlx_window window, t_slmap mapdata, char *rsc_path)
{
	t_gamestate	state;

	state.entities = gamestate_init_entities(window, mapdata, rsc_path);
	if (NULL == state.entities.collectibles)
		error("map has no collectibles");
	if (NULL == state.entities.exit)
		error("map has no collectibles");
	if (NULL == state.entities.player)
		error("map has no collectibles");
	state.map = mapdata;
	state.terrain_sprites.wall
		= sprite_load(window.mlx, rsc_path, "wall_fallback.xpm");
	state.terrain_sprites.floor
		= sprite_load(window.mlx, rsc_path, "floor.xpm");
	return (state);
}
#endif
