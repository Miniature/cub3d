/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamestate_init_terrain.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 09:43:36 by wdavey            #+#    #+#             */
/*   Updated: 2024/03/04 18:44:04 by wdavey           ###   ########.fr       */
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
	int			p[2];
	t_sprite	terrain[2];

	image = mlxw_new_image(window.mlx, 32 * map.width, 32 * map.height);
	ft_memset(p, 0, sizeof(*p) * 2);
	terrain[1] = sprite_load(window.mlx, rsc_path, "wall_fallback.xpm");
	terrain[0] = sprite_load(window.mlx, rsc_path, "floor.xpm");
	while ((unsigned)p[1] < map.height)
	{
		p[0] = 0;
		while ((unsigned)p[0] < map.width)
		{
			mlxw_image_overlay(image,
				terrain[WALL_CHAR == map.raw[p[1]][p[0]]].frames[0],
				pos_new(p[0] * 32, p[1] * 32));
			p[0]++;
		}
		p[1]++;
	}
	sprite_delete(terrain + 1, window.mlx);
	sprite_delete(terrain, window.mlx);
	return (image);
}
