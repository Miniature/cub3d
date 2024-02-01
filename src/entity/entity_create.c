/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:09:18 by wdavey            #+#    #+#             */
/*   Updated: 2024/02/01 14:06:45 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity.h"

t_entity	entity_create(enum e_id id, int x, int y, t_sprite *sprite)
{
	t_entity	e;

	e.type = id;
	e.pos.x = x;
	e.pos.y = y;
	e.facing = 0.0f;
	e.sprite = sprite;
	e.data = 0;
	return (e);
}
