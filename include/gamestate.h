/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamestate.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:34:15 by wdavey            #+#    #+#             */
/*   Updated: 2024/02/01 16:02:03 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMESTATE_H
# define GAMESTATE_H

# include "libft.h"

# include "mlxw.h"
# include "slmap.h"
# include "entity.h"

# define DISPLAY_WIDTH 640
# define DISPLAY_HEIGHT 480
# define TEXTURE_RESOLUTION 128

typedef struct s_gamestate_entities
{
	t_entity	*player;
	t_entity	*exit;
	t_list		*collectibles;
	t_list		*patrols;
}	t_gamestate_entities;

typedef struct s_gamestate_terrains
{
	t_sprite	wall;
	t_sprite	floor;
}	t_gamestate_terrains;

typedef struct s_gamestate
{
	t_gamestate_entities	entities;
	t_gamestate_terrains	terrain_sprites;
	t_mlx_image				terrain;
	t_mlx_image				background_img;
	t_slmap					map;
}	t_gamestate;

typedef struct s_gamestate_pespective
{
	float	pos_x;
	float	pos_y;
	float	map_x;
	float	map_y;
	double	cam_x;//cam x scan position
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;
	int		wall_side;
	double	persp_wall_dist;
	double	plane_x;
	double	plane_y;


	int		column_start;
	int		column_end;
	double	step;
	double	tex_pos;
	int		tex_x;
	int		tex_y;
}	t_gamestate_perspective;

typedef struct s_gamewindow
{
	t_mlx_window			win;
	t_gamestate				game;
	t_gamestate_perspective	*p;
	int						display_width; //window size
	int						display_height;
	int						render_scale;
}	t_gamewindow;

t_gamestate	gamestate_init(t_mlx_window window,
				t_slmap mapdata, char *rsc_path);
int			gamestate_render(t_gamewindow *gw);
void		gamestate_destroy(t_gamestate state, t_mlx_window win);

#endif
