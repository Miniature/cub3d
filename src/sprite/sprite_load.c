/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:10:36 by wdavey            #+#    #+#             */
/*   Updated: 2023/09/04 11:32:06 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

#include "libft.h"

#include "sprite.h"
#include "entity.h"

t_sprite	sprite_load(void *mlx, const char *rsc_path, const char *name)
{
	t_sprite	sprite;
	char		*img_path;

	sprite.frame_count = 1;
	sprite.frame_dur = malloc(1 * sizeof(*(sprite.frame_dur)));
	sprite.frame_dur[0] = -1;
	sprite.frames = malloc(1 * sizeof(*(sprite.frames)));
	img_path = ft_strjoin(rsc_path, name);
	sprite.frames[0] = mlxw_load_xpm(mlx, img_path);
	free(img_path);
	return (sprite);
}

t_sprite	sprite_load_patrol(void *mlx, char *rsc_path)
{
	t_sprite	sprite;
	char		*img_path;

	sprite.frame_count = 4;
	sprite.frame_dur = malloc(4 * sizeof(*(sprite.frame_dur)));
	sprite.frame_dur[0] = -1;
	sprite.frame_dur[1] = -1;
	sprite.frame_dur[2] = -1;
	sprite.frame_dur[3] = -1;
	sprite.frames = malloc(4 * sizeof(*(sprite.frames)));
	img_path = ft_strjoin(rsc_path, "secbot_n.xpm");
	sprite.frames[NORTH] = mlxw_load_xpm(mlx, img_path);
	free(img_path);
	img_path = ft_strjoin(rsc_path, "secbot_s.xpm");
	sprite.frames[SOUTH] = mlxw_load_xpm(mlx, img_path);
	free(img_path);
	img_path = ft_strjoin(rsc_path, "secbot_e.xpm");
	sprite.frames[EAST] = mlxw_load_xpm(mlx, img_path);
	free(img_path);
	img_path = ft_strjoin(rsc_path, "secbot_w.xpm");
	sprite.frames[WEST] = mlxw_load_xpm(mlx, img_path);
	free(img_path);
	return (sprite);
}

t_sprite	sprite_load_player(void *mlx, char *rsc_path)
{
	t_sprite	sprite;
	char		*img_path;

	sprite.frame_count = 4;
	sprite.frame_dur = malloc(4 * sizeof(*(sprite.frame_dur)));
	sprite.frame_dur[0] = PLAYER_SPRITE_CYCLE_TIME / 4;
	sprite.frame_dur[1] = PLAYER_SPRITE_CYCLE_TIME / 4;
	sprite.frame_dur[2] = PLAYER_SPRITE_CYCLE_TIME / 4;
	sprite.frame_dur[3] = PLAYER_SPRITE_CYCLE_TIME / 4;
	sprite.frames = malloc(4 * sizeof(*(sprite.frames)));
	img_path = ft_strjoin(rsc_path, "cleanbot1.xpm");
	sprite.frames[0] = mlxw_load_xpm(mlx, img_path);
	free(img_path);
	img_path = ft_strjoin(rsc_path, "cleanbot2.xpm");
	sprite.frames[1] = mlxw_load_xpm(mlx, img_path);
	free(img_path);
	img_path = ft_strjoin(rsc_path, "cleanbot3.xpm");
	sprite.frames[2] = mlxw_load_xpm(mlx, img_path);
	free(img_path);
	img_path = ft_strjoin(rsc_path, "cleanbot4.xpm");
	sprite.frames[3] = mlxw_load_xpm(mlx, img_path);
	free(img_path);
	return (sprite);
}
