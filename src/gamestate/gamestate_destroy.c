/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamestate_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:53:15 by wdavey            #+#    #+#             */
/*   Updated: 2023/09/02 13:14:04 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

#include "gamestate.h"
#include "mlxw.h"

#ifdef GAMESTATE_USE_TERRAIN_IMAGE

void	gamestate_destroy(t_gamestate state, t_mlx_window win)
{
	t_list	*entities;

	entities = state.entities.collectibles;
	while (NULL != entities)
	{
		entity_destroy(*(t_entity *)(entities->content), win);
		entities = entities->next;
	}
	entities = state.entities.patrols;
	while (NULL != entities)
	{
		entity_destroy(*(t_entity *)(entities->content), win);
		entities = entities->next;
	}
	ft_lstclear(&entities, free);
	sprite_delete(&(state.terrain_sprites.floor), win.mlx);
	sprite_delete(&(state.terrain_sprites.wall), win.mlx);
	mlxw_destroy_image(state.terrain, win.mlx);
	slmap_delete(state.map);
}
#else

void	gamestate_destroy(t_gamestate state, t_mlx_window win)
{
	t_list	*entities;

	entities = state.entities.collectibles;
	while (NULL != entities)
	{
		entity_destroy(*(t_entity *)(entities->content), win);
		entities = entities->next;
	}
	entities = state.entities.patrols;
	while (NULL != entities)
	{
		entity_destroy(*(t_entity *)(entities->content), win);
		entities = entities->next;
	}
	ft_lstclear(&entities, free);
	sprite_delete(&(state.terrain_sprites.floor), win.mlx);
	sprite_delete(&(state.terrain_sprites.wall), win.mlx);
	slmap_delete(state.map);
}
#endif
