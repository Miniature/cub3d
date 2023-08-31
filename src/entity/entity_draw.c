/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:00:58 by wdavey            #+#    #+#             */
/*   Updated: 2023/08/30 13:55:14 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity.h"
#include "sprite.h"

void	entity_draw(t_entity e, t_mlx_window w)
{
	sprite_draw(*(e.sprite), w, e.pos);
}
