/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:46:41 by wdavey            #+#    #+#             */
/*   Updated: 2023/08/31 12:47:36 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity.h"
#include "sprite.h"
#include "mlxw.h"

void	entity_destroy(t_entity e, t_mlx_window win)
{
	sprite_delete(*(e.sprite), win.mlx);
}
