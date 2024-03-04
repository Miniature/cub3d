/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_enclosed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:13:59 by wdavey            #+#    #+#             */
/*   Updated: 2024/03/04 17:44:33 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "slmap.h"
#include "entity.h"
#include <stdbool.h>
#include "libft.h"
#include <stdlib.h>

#define PLAYAREA_CHARS "0"

static bool	is_valid_playarea_char(char c)
{
	size_t	iii;

	iii = -1;
	while ('\0' != PLAYAREA_CHARS[++iii])
	{
		if (PLAYAREA_CHARS[iii] == c)
			return (true);
	}
	return (false);
}

//very slow on big maps, but oh well they shouldnt be hundreds of tiles across
static bool	valid_playarea_recurse(t_slmap map, t_pos pos, bool **checked)
{
	if (0 > pos.x || 0 > pos.y
		|| ft_strlen(map.raw[(int)pos.y]) <= pos.x || pos.y >= map.height)
		return (false);
	if (true == checked[(int)pos.y][(int)pos.x])
		return (true);
	checked[(int)pos.y][(int)pos.x] = true;
	if (WALL_CHAR == map.raw[(int)pos.y][(int)pos.x])
		return (true);
	if (!is_valid_playarea_char(map.raw[(int)pos.y][(int)pos.x]))
	{
		return (error("invalid character"), false);
	}
	if (!valid_playarea_recurse(map, pos_add(pos, (t_pos){-1, 0}), checked))
		return (false);
	if (!valid_playarea_recurse(map, pos_add(pos, (t_pos){1, 0}), checked))
		return (false);
	if (!valid_playarea_recurse(map, pos_add(pos, (t_pos){0, -1}), checked))
		return (false);
	if (!valid_playarea_recurse(map, pos_add(pos, (t_pos){0, 1}), checked))
		return (false);
	return (true);
}

bool	valid_playarea(t_slmap map, t_pos origin)
{
	bool	**checked;
	size_t	i;

	checked = malloc(sizeof(*checked) * map.height);
	i = -1;
	while (map.height > ++i)
	{
		checked[i] = ft_calloc(ft_strlen(map.raw[i]), sizeof(**checked));
	}
	checked[(int)origin.y][(int)origin.x] = true;
	if (!valid_playarea_recurse(map, pos_add(origin, (t_pos){-1, 0}), checked))
		return (false);
	if (!valid_playarea_recurse(map, pos_add(origin, (t_pos){1, 0}), checked))
		return (false);
	if (!valid_playarea_recurse(map, pos_add(origin, (t_pos){0, -1}), checked))
		return (false);
	if (!valid_playarea_recurse(map, pos_add(origin, (t_pos){0, 1}), checked))
		return (false);
	return (true);
}
