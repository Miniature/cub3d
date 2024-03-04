/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_get_copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:27:44 by wdavey            #+#    #+#             */
/*   Updated: 2024/03/04 18:06:59 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>

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

static t_entity	entity_get_copy_player(void *mlx, char *rsc_path, enum e_id id)
{
	static t_entity	player;
	static t_sprite	player_sprite;

	if (NONE_ID == player.type)
	{
		player_sprite = sprite_load_player(mlx, rsc_path);
		player.type = PLAYER_ID;
		player.sprite = &player_sprite;
		player.data = 0;
	}
	if (PLAYER_NORTH == id)
		player.facing = 0;
	if (PLAYER_EAST == id)
		player.facing = M_PI_2 * 3;
	if (PLAYER_SOUTH == id)
		player.facing = M_PI;
	if (PLAYER_WEST == id)
		player.facing = M_PI_2;
	return (player);
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
		if (PLAYER_NORTH == id || PLAYER_SOUTH == id
			|| PLAYER_EAST == id || PLAYER_WEST == id)
			entities[id] = entity_get_copy_player(mlx, rsc_path, id);
		else if (PATROL_ID == id)
			entities[id] = entity_get_copy_patrol(mlx, rsc_path);
		else
		{
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
