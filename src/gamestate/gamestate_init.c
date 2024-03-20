/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamestate_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:56:36 by wdavey            #+#    #+#             */
/*   Updated: 2024/03/20 21:07:44 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>

#include "libft.h"

#include "gamestate.h"
#include "slmap.h"
#include "mlxw.h"

t_mlx_image				gamestate_init_terrain(t_mlx_window window,
							t_slmap map, char *rsc_path, size_t start);
t_mlx_image				gamestate_init_background(t_mlx_window window,
							int width, int height);
t_gamestate_entities	gamestate_init_entities(t_mlx_window window,
							t_slmap mapdata, char *rsc_path, size_t start);
size_t					gamestate_init_config(t_gamestate *state, void *mlx,
							char *rsc_path);
bool					valid_playarea(t_slmap map, t_pos origin);

void	gamestate_has_path_adj(t_slmap map, bool **result, t_pos pos)
{
	if (true == result[(int)round(pos.y)][(int)round(pos.x)])
		return ;
	if (WALL_CHAR != map.raw[(int)round(pos.y)][(int)round(pos.x)])
	{
		result[(int)round(pos.y)][(int)round(pos.x)] = true;
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
	i = -1;
	while (++i < state.map.height)
		pathable[i] = ft_calloc(ft_strlen(state.map.raw[i]),
				sizeof(**pathable));
	gamestate_has_path_adj(state.map, pathable, state.entities.player->pos);
	result = pathable[(int)round(state.entities.exit->pos.y)]
	[(int)round(state.entities.exit->pos.x)];
	i = 0;
	while (i < state.map.height)
		free(pathable[i++]);
	free(pathable);
	return (result);
}

bool	gamestate_is_valid(t_gamestate state)
{
	t_pos	p;

	if (NULL == state.entities.player)
		error("no player spawn location");
	p = pos_new(0, 0);
	if (!valid_playarea(state.map, state.entities.player->pos))
		error("map is not enclosed");
	return (true);
}

t_gamestate	gamestate_init(t_mlx_window window, t_slmap mapdata, char *rsc_path)
{
	t_gamestate	state;
	size_t		config_lines;

	state.map = mapdata;
	state.raycast_img = gamestate_init_background(window, DISPLAY_WIDTH,
			DISPLAY_HEIGHT);
	config_lines = gamestate_init_config(&state, window.mlx, rsc_path);
	state.entities = gamestate_init_entities(window, mapdata, rsc_path,
			config_lines + 1);
	state.terrain_sprites.wall
		= sprite_load(window.mlx, rsc_path, "wall_fallback.xpm");
	state.terrain_sprites.floor
		= sprite_load(window.mlx, rsc_path, "floor.xpm");
	if (false == gamestate_is_valid(state))
		error("unknown error");
	return (state);
}
