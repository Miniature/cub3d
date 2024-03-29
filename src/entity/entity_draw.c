/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:00:58 by wdavey            #+#    #+#             */
/*   Updated: 2023/09/04 11:25:12 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity.h"
#include "sprite.h"

void	entity_draw(t_entity e, t_mlx_window w)
{
	if (e.type == PATROL_ID)
	{
		sprite_draw_patrol(*(e.sprite), w, e.pos, e.data);
	}
	else if (e.type == PLAYER_ID)
	{
		sprite_draw_player(*(e.sprite), w, e.pos);
	}
	else
	{
		sprite_draw(*(e.sprite), w, e.pos);
	}
}
