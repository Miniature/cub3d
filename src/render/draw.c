/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:52:32 by ihogben           #+#    #+#             */
/*   Updated: 2024/02/14 13:52:33 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	img_pix_put(t_gamewindow *gw, t_mlx_image *img,  int x, int y, int color)
{
	char	*pixel;

	if (y < 0 || y > gw->display_height - 1 || x < 0
		|| x > gw->display_width - 1)
		return ;
	pixel = (img->addr + (y * img->line_len
				+ x * (img->bpp / 8)));
	*(int *)pixel = color;
}