/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamestate_render.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 09:51:22 by wdavey            #+#    #+#             */
/*   Updated: 2023/09/04 11:45:22 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "gamestate.h"
#include "entity.h"
#include "sprite.h"

void	gamestate_render_terrain(t_gamestate state, t_mlx_window win)
{
	mlxw_draw(win, state.terrain, pos_new(0, 0));
}

int	gamestate_render(t_gamewindow *gw)
{
	t_list		*entity_list;
	t_entity	*entity;

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
	entity_draw(*gw->game.entities.exit, gw->win);
	entity_draw(*gw->game.entities.player, gw->win);
	return (0);
}
