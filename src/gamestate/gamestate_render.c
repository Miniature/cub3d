/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamestate_render.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 09:51:22 by wdavey            #+#    #+#             */
/*   Updated: 2024/03/04 17:41:03 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

#include "gamestate.h"
#include "entity.h"
#include "sprite.h"
#include "render.h"

void	gamestate_render_terrain(t_gamestate state, t_mlx_window win)
{
	mlxw_draw(win, state.terrain, pos_new(0, 0));
}

void	gamestate_render_movestr(t_gamewindow *gw)
{
	char	*movestr;

	mlxw_draw_string(gw->win, "moves:",
		pos_new(16, 20), mlxw_rgb(255, 255, 255));
	movestr = ft_itoa(gw->game.entities.player->data);
	mlxw_draw_string(gw->win, movestr, pos_new(80, 20),
		mlxw_rgb(255, 255, 255));
	free(movestr);
}

int	gamestate_render(t_gamewindow *gw)
{
	t_list		*entity_list;
	t_entity	*entity;

	gamestate_render_terrain(gw->game, gw->win);
	render_raycasting(gw);//running before gamestate_render_terrain, causes visual tearing but allows view of map
	gamestate_render_terrain(gw->game, gw->win);
	entity_list = gw->game.entities.collectibles;
	while (NULL != entity_list)
	{
		entity = ((t_entity *)(entity_list->content));
		entity_draw(*entity, gw->win);
		entity_list = entity_list->next;
	}
	entity_list = gw->game.entities.patrols;
	while (NULL != entity_list)
	{
		entity = ((t_entity *)(entity_list->content));
		entity_draw(*entity, gw->win);
		entity_list = entity_list->next;
	}
	//entity_draw(*gw->game.entities.exit, gw->win);
	entity_draw(*gw->game.entities.player, gw->win);
	//gamestate_render_movestr(gw);
	return (0);
}
