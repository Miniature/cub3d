/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:46:25 by wdavey            #+#    #+#             */
/*   Updated: 2023/08/30 14:49:54 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "sprite.h"
#include "mlx.h"

void	sprite_delete(t_sprite sprite, void *mlx)
{
	size_t	i;

	free(sprite.frame_dur);
	i = 0;
	while (i < sprite.frame_count)
	{
		mlxw_destroy_image(sprite.frames[i], mlx);
		i++;
	}
}
