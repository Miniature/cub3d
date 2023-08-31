/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamestate_init_entities.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 09:47:40 by wdavey            #+#    #+#             */
/*   Updated: 2023/08/31 11:29:35 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "gamestate.h"
#include "entity.h"

char	*sprite_name_from_eid(enum e_id id)
{
	if (PLAYER_ID == id)
		return ("cleanbot1.xpm");
	if (PATROL_ID == id)
		return ("secbox_s.xpm");
	if (COLLECTIBLE_ID == id)
		return ("dirt.xpm");
	if (EXIT_ID == id)
		return ("charger.xpm");
	error("tried to get sprite for invalid entity id");
	return (NULL);
}

//does this count as lazy init?
//shallow copy is wanted to avoid duplicating image data
t_entity	*get_entity_copy(enum e_id id, void *mlx, char *rsc_path, t_pos pos)
{
	static t_entity	entities[INVALID_ID];
	static t_sprite	sprites[INVALID_ID];
	t_entity		*new;

	if (NONE_ID >= id || INVALID_ID <= id)
		error("tried to get invalid entity");
	if (NONE_ID == entities[id].type)
	{
		sprites[id] = sprite_load(mlx, rsc_path, sprite_name_from_eid(id));
		entities[id] = entity_create(id, 0, 0, sprites + id);
	}
	new = ft_memcpy(malloc(sizeof(t_entity)),
			entities + id, sizeof(t_entity));
	new->pos = pos;
	return (new);
}

enum e_id	e_id_from_char(char c)
{
	if (c == PLAYER_CHAR)
		return (PLAYER_ID);
	if (c == PATROL_CHAR)
		return (PATROL_ID);
	if (c == COLLECTIBLE_CHAR)
		return (COLLECTIBLE_ID);
	if (c == EXIT_CHAR)
		return (EXIT_ID);
	return (INVALID_ID);
}

t_list	*gamestate_init_entities(t_mlx_window window,
		t_slmap mapdata, char *rsc_path)
{
	t_list		*entities;
	t_pos		p;
	enum e_id	e_id;

	entities = NULL;
	p.y = 0;
	while (p.y < mapdata.height)
	{
		p.x = 0;
		while (p.x < mapdata.width)
		{
			if (!(mapdata.raw[p.y][p.x] == WALL_CHAR
				|| mapdata.raw[p.y][p.x] == FLOOR_CHAR))
			{
				e_id = e_id_from_char(mapdata.raw[p.y][p.x]);
				if (INVALID_ID == e_id)
					error("invalid character in map");
				ft_lstadd_back(&(entities), ft_lstnew(get_entity_copy(
							e_id, window.mlx, rsc_path, pos_new(p.x, p.y))));
			}
			p.x++;
		}
		p.y++;
	}
	return (entities);
}
