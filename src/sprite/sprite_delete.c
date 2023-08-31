/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:46:25 by wdavey            #+#    #+#             */
/*   Updated: 2023/08/31 12:48:48 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "sprite.h"
#include "mlx.h"

void	sprite_delete(t_sprite sprite, void *mlx)
{
	size_t	i;

	if (NULL != sprite.frame_dur)
	{
		free(sprite.frame_dur);
		sprite.frame_dur = NULL;
	}
	if (NULL != sprite.frames)
	{
		i = 0;
		while (i < sprite.frame_count)
		{
			mlxw_destroy_image(sprite.frames[i], mlx);
			i++;
		}
		free(sprite.frames);
		sprite.frames = NULL;
	}
}
