/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_draw_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:56:38 by wdavey            #+#    #+#             */
/*   Updated: 2023/09/04 12:13:32 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>

#include "mlx.h"

#include "sprite.h"
#include "entity.h"
#include "mlxw.h"

void	sprite_draw(t_sprite sprite, t_mlx_window win, t_pos pos)
{
	mlxw_draw(win, sprite.frames[0], pos_new(pos.x * 32, pos.y * 32));
}

void	sprite_draw_patrol(t_sprite sprite, t_mlx_window win, t_pos pos,
			int facing)
{
	mlxw_draw(win, sprite.frames[facing], pos_new(pos.x * 32, pos.y * 32));
}

void	sprite_draw_player(t_sprite sprite, t_mlx_window win, t_pos pos)
{
	clock_t	time;
	clock_t	sum;
	size_t	i;

	time = clock();
	i = 0;
	sum = 0;
	while (i < sprite.frame_count)
		sum += sprite.frame_dur[i++];
	time = time % sum;
	i = 0;
	while (time > sum + sprite.frame_dur[i])
		sum += sprite.frame_dur[i++];
	mlxw_draw(win, sprite.frames[i], pos_new(pos.x * 32, pos.y * 32));
}

	//time = (time / (PLAYER_SPRITE_CYCLE_TIME / sprite.frame_count))
	//	% sprite.frame_count;
