/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:52:32 by ihogben           #+#    #+#             */
/*   Updated: 2024/02/14 13:52:33 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include "render.h"
#include "ft_printf.h"

void	raycasting_init(t_gamewindow *gw, int x)
{
	gw->p->map_x = gw->game.entities.player->pos.x;
	gw->p->map_y = gw->game.entities.player->pos.y;
	gw->p->pos_x = gw->p->map_x;
	gw->p->pos_y = gw->p->map_y;
	gw->p->cam_x = 2 * x / (double)gw->display_width - 1;
	//gw->p->plane_x = cos(gw->game.entities.player->facing) * -1 * 0.66f; //fix camera plane rotation
	//gw->p->plane_y = sin(gw->game.entities.player->facing) * -1 * 0.66f;
	gw->p->ray_dir_x = cos(gw->game.entities.player->facing) + gw->p->plane_x * gw->p->cam_x;
	gw->p->ray_dir_y = sin(gw->game.entities.player->facing) + gw->p->plane_y * gw->p->cam_x;
}

void	get_delta_dist(t_gamestate_perspective *p)
{
	if (p->ray_dir_x == 0)
		p->delta_dist_x = INT_MAX;
	else
		p->delta_dist_x = fabs(1 / p->ray_dir_x);
	if (p->ray_dir_y == 0)
		p->delta_dist_y = INT_MAX;
	else
		p->delta_dist_y = fabs(1 / p->ray_dir_y);
}

void	get_step(t_gamestate_perspective *p)
{
	if (p->ray_dir_x < 0)
	{
		p->step_x = -1;
		p->side_dist_x = (p->pos_x - p->map_x) * p->delta_dist_x;
	}
	else
	{
		p->step_x = 1;
		p->side_dist_x = (p->map_x + 1.0 - p->pos_x) * p->delta_dist_x;
	}
	if (p->ray_dir_y < 0)
	{
		p->step_y = -1;
		p->side_dist_y = (p->pos_y - p->map_y) * p->delta_dist_y;
	}
	else
	{
		p->step_y = 1;
		p->side_dist_y = (p->map_y + 1.0 - p->pos_y) * p->delta_dist_y;
	}
}

void	get_wall_normal(t_gamestate_perspective *p, t_gamewindow *gw)
{
	int	wall;

	wall = 0;
	while (wall == 0)
	{
		if (p->side_dist_x < p->side_dist_y)
		{
			p->side_dist_x += p->delta_dist_x;
			p->map_x += p->step_x;
			p->wall_side = 0;
		}
		else
		{
			p->side_dist_y += p->delta_dist_y;
			p->map_y += p->step_y;
			p->wall_side = 1;
		}
		if (slmap_get_block(gw->game.map, p->map_x, p->map_y) == '1')
			wall = 1;
	}
}

void	raycasting(t_gamewindow *gw)
{
	int	x;

	x = 0;
	while (x < gw->display_width) //add render scale later
	{
		raycasting_init(gw, x);
		get_delta_dist(gw->p);
		get_step(gw->p);
		get_wall_normal(gw->p, gw);
		if (gw->p->wall_side == 0)
			gw->p->persp_wall_dist = ((gw->p->side_dist_x - gw->p->delta_dist_x));
		else
			gw->p->persp_wall_dist = ((gw->p->side_dist_y - gw->p->delta_dist_y));
		draw_column(gw, x);
		x++;
	}
}
