/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:04:03 by wdavey            #+#    #+#             */
/*   Updated: 2023/08/31 16:09:25 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "entity.h"
#include "utils.h"

void	player_move(t_entity *player, t_pos move)
{
	static size_t	moves;

	player->pos = pos_add(player->pos, move);
	ft_printf("moves: %d\n", (int)++moves);
}
