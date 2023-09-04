/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:04:03 by wdavey            #+#    #+#             */
/*   Updated: 2023/09/04 12:57:15 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "entity.h"
#include "utils.h"

void	player_move(t_entity *player, t_pos move)
{
	player->pos = pos_add(player->pos, move);
	ft_printf("moves: %d\n", (int)++(player->data));
}
