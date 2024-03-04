/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_enclosed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:13:59 by wdavey            #+#    #+#             */
/*   Updated: 2024/03/04 17:02:13 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "slmap.h"
#include "entity.h"
#include <stdbool.h>
#include "libft.h"
#include <stdlib.h>

//very slow on big maps, but oh well they shouldnt be hundreds of tiles across
static bool	enclosed_recurse(t_slmap map, t_pos pos, bool **checked)
{
	if (0 > pos.x || 0 > pos.y
		|| ft_strlen(map.raw[(int)pos.y]) <= pos.x || pos.y >= map.height)
		return (false);
	if (true == checked[(int)pos.y][(int)pos.x])
		return (true);
	checked[(int)pos.y][(int)pos.x] = true;
	//if (WALL_CHAR == slmap_get_block(map, pos.y, pos.x))
	if (WALL_CHAR == map.raw[(int)pos.y][(int)pos.x])
		return (true);
	if (!enclosed_recurse(map, pos_add(pos, (t_pos){-1, 0}), checked))
		return (false);
	if (!enclosed_recurse(map, pos_add(pos, (t_pos){1, 0}), checked))
		return (false);
	if (!enclosed_recurse(map, pos_add(pos, (t_pos){0, -1}), checked))
		return (false);
	if (!enclosed_recurse(map, pos_add(pos, (t_pos){0, 1}), checked))
		return (false);
	return (true);
}

bool	is_map_enclosed(t_slmap map, t_pos origin)
{
	bool	**checked;
	size_t	i;

	checked = malloc(sizeof(*checked) * map.height);
	i = -1;
	while (map.height > ++i)
	{
		checked[i] = ft_calloc(ft_strlen(map.raw[i]), sizeof(**checked));
	}
	return (enclosed_recurse(map, origin, checked));
}
