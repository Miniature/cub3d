/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamestate_init_player.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 06:46:13 by wdavey            #+#    #+#             */
/*   Updated: 2024/02/26 16:10:44 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gamestate.h"

#include "libft.h"

static t_entity	*player_from_line(char *line)
{
	t_entity	*player;


	return (NULL);
}

t_gamestate_entities	gamestate_init_entities(t_mlx_window window,
	t_slmap mapdata, size_t start_line)
{
	t_gamestate_entities	entities;
	size_t					line;

	line = start_line - 1;
	ft_memset(&entities, 0, sizeof(entities));
	while (NULL != mapdata.raw[++line])
	{
		entities.player = player_from_line(line);
		if (NULL != entities.player)
		{
			entities.player->pos.y = line;
			break ;
		}
	}
	return (entities);
}
