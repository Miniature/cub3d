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

# define DISPLAY_WIDTH 1280
# define DISPLAY_HEIGHT 960

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

typedef struct s_gamewindow
{
	t_mlx_window	win;
	t_gamestate		game;
	int	display_width; //window size
	int	display_height;
}	t_gamewindow;

t_gamestate	gamestate_init(t_mlx_window window,
				t_slmap mapdata, char *rsc_path);
int			gamestate_render(t_gamewindow *gw);
void		gamestate_destroy(t_gamestate state, t_mlx_window win);

#endif
