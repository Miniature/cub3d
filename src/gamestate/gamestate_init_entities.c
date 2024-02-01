/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamestate_init_entities.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 09:47:40 by wdavey            #+#    #+#             */
/*   Updated: 2024/02/01 14:35:09 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>

#include "gamestate.h"
#include "entity.h"

t_list	*entities_from_slmap(t_mlx_window window,
		t_slmap mapdata, char *rsc_path)
{
	t_list		*entities;
	t_pos		p;
	enum e_id	e_id;

	entities = NULL;
	p.y = 0;
	while (p.y < (signed)mapdata.height)
	{
		p.x = 0;
		while (p.x < (signed)mapdata.width)
		{
			if (!(mapdata.raw[(int)round(p.y)][(int)round(p.x)] == WALL_CHAR
				|| mapdata.raw[(int)round(p.y)][(int)round(p.x)] == FLOOR_CHAR))
			{
				e_id = e_id_from_char(
						mapdata.raw[(int)round(p.y)][(int)round(p.x)]);
				if (INVALID_ID == e_id)
					error("invalid character in map");
				ft_lstadd_back(&(entities), ft_lstnew(entity_get_copy(
							e_id, window.mlx, rsc_path, pos_new(p.x, p.y))));
			}
			p.x++;
		}
		p.y++;
	}
	return (entities);
}

void	gamestate_entity_add(t_gamestate_entities *ents, t_entity *ent)
{
	if (PLAYER_ID == ent->type)
	{
		if (NULL != ents->player)
			error("multiple spawn locations in map");
		ents->player = ent;
	}
	else if (EXIT_ID == ent->type)
	{
		if (NULL != ents->exit)
			error("multiple exit locations in map");
		ents->exit = ent;
	}
	else if (COLLECTIBLE_ID == ent->type)
		ft_lstadd_front(&(ents->collectibles), ft_lstnew(ent));
	else if (PATROL_ID == ent->type)
		ft_lstadd_front(&(ents->patrols), ft_lstnew(ent));
	else
		error("loaded invalid entity");
}

t_gamestate_entities	gamestate_init_entities(t_mlx_window window,
							t_slmap mapdata, char *rsc_path)
{
	t_list					*ents;
	t_gamestate_entities	gs_ents;

	ents = entities_from_slmap(window, mapdata, rsc_path);
	ft_memset(&gs_ents, 0, sizeof(gs_ents));
	while (NULL != ents)
	{
		gamestate_entity_add(&gs_ents, ents->content);
		ents = ents->next;
	}
	return (gs_ents);
}
