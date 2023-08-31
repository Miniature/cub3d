/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamestate.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:34:15 by wdavey            #+#    #+#             */
/*   Updated: 2023/08/31 10:02:12 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMESTATE_H
# define GAMESTATE_H

# include "libft.h"

# include "mlxw.h"
# include "slmap.h"

typedef struct s_gamestate {
	t_list		*entities;
	t_mlx_image	terrain;
	t_slmap		map;
}	t_gamestate;

t_gamestate	gamestate_init(t_mlx_window window,
				t_slmap mapdata, char *rsc_path);
void		gamestate_render(t_gamestate state, t_mlx_window win);

#endif
