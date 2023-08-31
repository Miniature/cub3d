/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamestate_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:56:36 by wdavey            #+#    #+#             */
/*   Updated: 2023/08/31 09:49:13 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "gamestate.h"
#include "slmap.h"
#include "mlxw.h"

t_mlx_image	gamestate_init_terrain(t_mlx_window window,
				t_slmap map, char *rsc_path);
t_list		*gamestate_init_entities(t_mlx_window window,
				t_slmap mapdata, char *rsc_path);

t_gamestate	gamestate_init(t_mlx_window window, t_slmap mapdata, char *rsc_path)
{
	t_gamestate	state;

	state.terrain = gamestate_init_terrain(window, mapdata, rsc_path);
	state.entities = gamestate_init_entities(window, mapdata, rsc_path);
	state.map = mapdata;
	return (state);
}
