/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:09:18 by wdavey            #+#    #+#             */
/*   Updated: 2023/08/31 10:18:13 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity.h"

t_entity	entity_create(enum e_id type, int x, int y, t_sprite *sprite)
{
	t_entity	e;

	e.type = type;
	e.pos.x = x;
	e.pos.y = y;
	e.sprite = sprite;
	return (e);
}
