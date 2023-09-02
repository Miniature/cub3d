/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_get_copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:27:44 by wdavey            #+#    #+#             */
/*   Updated: 2023/09/02 12:32:01 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

#include "entity.h"

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
		sprites[id] = sprite_load(mlx, rsc_path, sprite_name_from_eid(id));
		entities[id] = entity_create(id, 0, 0, sprites + id);
	}
	new = ft_memcpy(malloc(sizeof(t_entity)),
			entities + id, sizeof(t_entity));
	new->pos = pos;
	return (new);
}
