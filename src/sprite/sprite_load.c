/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:10:36 by wdavey            #+#    #+#             */
/*   Updated: 2023/08/31 11:32:33 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

#include "libft.h"

#include "sprite.h"

t_sprite	sprite_load(void *mlx, const char *rsc_path, const char *name)
{
	t_sprite	sprite;
	char		*img_path;

	sprite.frame_count = 1;
	sprite.frame_dur = malloc(1 * sizeof(*(sprite.frame_dur)));
	sprite.frame_dur[0] = __FLT_MAX__;
	sprite.frames = malloc(1 * sizeof(*(sprite.frames)));
	img_path = ft_strjoin(rsc_path, name);
	sprite.frames[0] = mlxw_load_xpm(mlx, img_path);
	free(img_path);
	return (sprite);
}
