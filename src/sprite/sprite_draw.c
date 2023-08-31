/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:56:38 by wdavey            #+#    #+#             */
/*   Updated: 2023/08/31 11:27:45 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "sprite.h"
#include "mlxw.h"

/*
void	sprite_draw(const t_sprite sprite, t_mlx_window win, t_pos pos)
{
	mlx_put_image_to_window(win.mlx, win.win,
		sprite.frames[0].img, pos.x, pos.y);
}
*/
void	sprite_draw(t_sprite sprite, t_mlx_window win, t_pos pos)
{
	mlxw_draw(win, sprite.frames[0], pos_new(pos.x * 32, pos.y * 32));
}
