/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamestate_init_terrain.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 09:43:36 by wdavey            #+#    #+#             */
/*   Updated: 2023/09/02 14:26:52 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "mlxw.h"
#include "slmap.h"
#include "sprite.h"

t_mlx_image	gamestate_init_terrain(t_mlx_window window,
		t_slmap map, char *rsc_path)
{
	t_mlx_image	image;
	t_pos		p;
	t_sprite	terrain[2];

	image = mlxw_new_image(window.mlx, 32 * map.width, 32 * map.height);
	p = pos_new(0, 0);
	terrain[1] = sprite_load(window.mlx, rsc_path, "wall_fallback.xpm");
	terrain[0] = sprite_load(window.mlx, rsc_path, "floor.xpm");
	while ((unsigned)p.y < map.height)
	{
		if (ft_strlen(map.raw[p.y]) != map.width)
			error("map is not rectangular");
		p.x = 0;
		while ((unsigned)p.x < map.width)
		{
			mlxw_image_overlay(image,
				terrain[WALL_CHAR == map.raw[p.y][p.x]].frames[0],
				pos_new(p.x * 32 + 1, p.y * 32 + 1));
			p.x++;
		}
		p.y++;
	}
	sprite_delete(terrain + 1, window.mlx);
	sprite_delete(terrain, window.mlx);
	return (image);
}
