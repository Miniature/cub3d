/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamestate_render.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 09:51:22 by wdavey            #+#    #+#             */
/*   Updated: 2023/08/31 11:25:58 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "gamestate.h"
#include "entity.h"

void	gamestate_render(t_gamestate state, t_mlx_window win)
{
	t_list		*entity_list;
	t_entity	*entity;

	mlxw_draw(win, state.terrain, pos_new(0, 0));
	entity_list = state.entities;
	while (NULL != entity_list)
	{
		entity = ((t_entity *)(entity_list->content));
		entity_draw(*entity, win);
		entity_list = entity_list->next;
	}
}
