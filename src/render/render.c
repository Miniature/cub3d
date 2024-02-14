/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:30:06 by ihogben           #+#    #+#             */
/*   Updated: 2024/02/14 13:30:09 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <stdlib.h>

int	build_argb(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
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
				img_pix_put(gw, &gw->game.background_img, x, y, build_argb(255, 255, 255, 255));
			else
				img_pix_put(gw, &gw->game.background_img, x, y, build_argb(150, 150, 150, 150));
			y++;
		}
		++x;
	}
}

int	render(t_gamewindow *gw)
{
	render_background(gw);
	mlx_put_image_to_window(gw->win.mlx, gw->win.win, gw->game.background_img.img, 0, 0);
	return (0);
}
