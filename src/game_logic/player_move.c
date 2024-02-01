/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:04:03 by wdavey            #+#    #+#             */
/*   Updated: 2024/02/01 15:56:30 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "entity.h"
#include "utils.h"

void	player_move(t_entity *player, t_pos move)
{
	player->pos = pos_add(player->pos, move);
}
