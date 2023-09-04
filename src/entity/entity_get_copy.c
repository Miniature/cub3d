/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_get_copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:27:44 by wdavey            #+#    #+#             */
/*   Updated: 2023/09/04 11:15:06 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

#include "entity.h"
#include "sprite.h"

static	t_entity	entity_get_copy_patrol(void *mlx, char *rsc_path)
{
	t_entity	patrol;

	patrol.type = PATROL_ID;
	patrol.pos = pos_new(0, 0);
	patrol.data = 0;
	patrol.sprite = malloc(1 * sizeof(*(patrol.sprite)));
	patrol.sprite[0] = sprite_load_patrol(mlx, rsc_path);
	return (patrol);
}

//does this count as lazy init?
//shallow copy is wanted to avoid duplicating image data
t_entity	*entity_get_copy(enum e_id id, void *mlx, char *rsc_path, t_pos pos)
{
	static t_entity	entities[INVALID_ID];
	static t_sprite	sprites[INVALID_ID];
	t_entity		*new;

	if (NONE_ID >= id || INVALID_ID <= id)
		error("tried to get invalid entity");
	if (NONE_ID == entities[id].type)
	{
		if (PATROL_ID == id)
			entities[id] = entity_get_copy_patrol(mlx, rsc_path);
		else
		{
			if (PLAYER_ID == id)
				sprites[id] = sprite_load_player(mlx, rsc_path);
			else
				sprites[id] = sprite_load(mlx, rsc_path,
						sprite_name_from_eid(id));
			entities[id] = entity_create(id, 0, 0, sprites + id);
		}
	}
	new = ft_memcpy(malloc(sizeof(t_entity)),
			entities + id, sizeof(t_entity));
	new->pos = pos;
	return (new);
}
