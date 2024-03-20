/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamestate_render.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 09:51:22 by wdavey            #+#    #+#             */
/*   Updated: 2024/03/20 21:14:32 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

#include "gamestate.h"
#include "entity.h"
#include "sprite.h"
#include "render.h"

void	gamestate_render_minimap(t_gamewindow *gw);

int	gamestate_render(t_gamewindow *gw)
{
	gw->game.raycast_img = mlxw_new_image(gw->win.mlx,
			DISPLAY_WIDTH, DISPLAY_HEIGHT);
	render_raycasting(gw);
	gamestate_render_minimap(gw);
	mlx_put_image_to_window(gw->win.mlx, gw->win.win,
		gw->game.raycast_img.img, 0, 0);
	mlxw_destroy_image(gw->game.raycast_img, gw->win.mlx);
	return (0);
}
