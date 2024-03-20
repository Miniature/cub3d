/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:30:06 by ihogben           #+#    #+#             */
/*   Updated: 2024/03/20 21:08:48 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <stdlib.h>

int	get_colour(t_gamewindow *gw, int x, int y, int i)
{
	return (*(int *)(gw->game.wall_img[i].addr
		+ (y * gw->game.wall_img[i].line_len + x
			* (gw->game.wall_img[i].bpp / 8))));
}

void	render_background(t_gamewindow *gw)
{
	int	x;
	int	y;

	x = 0;
	while (x < gw->display_width)
	{
		y = 0;
		while (y < gw->display_height)
		{
			if (y < gw->display_height / 2)
				b_img_pix_put(gw, x, y, gw->game.ceiling_colour.colour);
			else
				b_img_pix_put(gw, x, y, gw->game.floor_colour.colour);
			y++;
		}
		++x;
	}
}

int	render_raycasting(t_gamewindow *gw)
{
	render_background(gw);
	raycasting(gw);
	return (0);
}
