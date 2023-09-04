/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamestate_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:56:36 by wdavey            #+#    #+#             */
/*   Updated: 2023/09/04 12:37:02 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

#include "gamestate.h"
#include "slmap.h"
#include "mlxw.h"

t_mlx_image				gamestate_init_terrain(t_mlx_window window,
							t_slmap map, char *rsc_path);
t_gamestate_entities	gamestate_init_entities(t_mlx_window window,
							t_slmap mapdata, char *rsc_path);

void	gamestate_has_path_adj(t_slmap map, bool **result, t_pos pos)
{
	if (true == result[pos.y][pos.x])
		return ;
	if (WALL_CHAR != map.raw[pos.y][pos.x])
	{
		result[pos.y][pos.x] = true;
		gamestate_has_path_adj(map, result, pos_add(pos, pos_new(1, 0)));
		gamestate_has_path_adj(map, result, pos_add(pos, pos_new(-1, 0)));
		gamestate_has_path_adj(map, result, pos_add(pos, pos_new(0, 1)));
		gamestate_has_path_adj(map, result, pos_add(pos, pos_new(0, -1)));
	}
}

bool	gamestate_has_path(t_gamestate state)
{
	bool	**pathable;
	bool	result;
	size_t	i;

	pathable = malloc(state.map.height * sizeof(*pathable));
	i = 0;
	while (i < state.map.height)
		pathable[i++] = ft_calloc(state.map.width, sizeof(**pathable));
	gamestate_has_path_adj(state.map, pathable, state.entities.player->pos);
	result = pathable[state.entities.exit->pos.y][state.entities.exit->pos.x];
	i = 0;
	while (i < state.map.height)
		free(pathable[i++]);
	free(pathable);
	return (result);
}

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
	if (false == gamestate_has_path(state))
		error("map has no valid path");
	return (true);
}

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
	if (false == gamestate_is_valid(state))
		error("unknown error");
	return (state);
}
