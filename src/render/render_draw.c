/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:52:32 by ihogben           #+#    #+#             */
/*   Updated: 2024/02/14 13:52:33 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "ft_printf.h"

void	b_img_pix_put(t_gamewindow *gw, int x, int y, int colour)
{
	char	*pixel;
	//gw->game.background_img.
	if (y < 0 || y > gw->display_height - 1 || x < 0
		|| x > gw->display_width - 1)
		return ;
	pixel = (gw->game.background_img.addr
			+ (y * gw->game.background_img.line_len
				+ x * (gw->game.background_img.bpp / 8)));
	*(int *)pixel = colour;
}

void	calculate_column
	(t_gamewindow *gw, int *line_height, int *start, int *end)
{
	*line_height = gw->display_height / gw->p->persp_wall_dist;
	*start = -*line_height / 2 + gw->display_height / 2;
	if (*start < 0)
		*start = 0;
	*end = *line_height / 2 + gw->display_height / 2;
	if (*end >= gw->display_height)
		*end = gw->display_height - 1;
}

void	get_texture(t_gamewindow *gw, int start, int line_height)
{
	double	wall_x;

	wall_x = 0;
	if (gw->p->wall_side == 0)
		wall_x = gw->p->pos_y + gw->p->persp_wall_dist * gw->p->ray_dir_y;
	else
		wall_x = gw->p->pos_x + gw->p->persp_wall_dist * gw->p->ray_dir_x;
	wall_x -= floor(wall_x);
	gw->p->tex_x = wall_x * TEXTURE_RESOLUTION;
	if (gw->p->wall_side == 0 && gw->p->ray_dir_x > 0)
		gw->p->tex_x = TEXTURE_RESOLUTION - gw->p->tex_x - 1;
	if (gw->p->wall_side == 1 && gw->p->ray_dir_y < 0)
		gw->p->tex_x = TEXTURE_RESOLUTION - gw->p->tex_x - 1;
	gw->p->step = 1.0 * TEXTURE_RESOLUTION / line_height;
	gw->p->tex_pos = (start - gw->display_height / 2
			+ line_height / 2) * gw->p->step;
}

void	draw(t_gamewindow *gw, int x, int texture)
{
	int	colour;

	colour = get_colour(gw, gw->p->tex_x, gw->p->tex_y, texture);
	b_img_pix_put(gw, x, gw->p->column_start, colour);
}

void	draw_column(t_gamewindow *gw, int x)
{
	int	line_height;

	calculate_column(gw, &line_height,
		&gw->p->column_start, &gw->p->column_end);
	get_texture(gw, gw->p->column_start, line_height);
	while (gw->p->column_start < gw->p->column_end)
	{
		gw->p->tex_y = (int)gw->p->tex_pos & (TEXTURE_RESOLUTION - 1);
		gw->p->tex_pos += gw->p->step;
		if (gw->p->wall_side == 1 && gw->p->ray_dir_y < 0)//SOUTH
			draw(gw, x, 2);
		else if (gw->p->wall_side == 1 && gw->p->ray_dir_y > 0)//NORTH
			draw(gw, x, 0);
		else if (gw->p->wall_side == 0 && gw->p->ray_dir_x < 0)//EAST
			draw(gw, x, 1);
		else if (gw->p->wall_side == 0 && gw->p->ray_dir_x > 0)//WEST
			draw(gw, x, 3);
		gw->p->column_start++;
	}
}
