/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:45:33 by wdavey            #+#    #+#             */
/*   Updated: 2024/02/01 16:02:40 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include <stddef.h>
# include <time.h>

# include "mlxw.h"
# include "utils.h"

# define PLAYER_SPRITE_CYCLE_TIME 500000 //(CLOCKS_PER_SEC / 2)

typedef struct s_sprite
{
	t_mlx_image	*frames;
	clock_t		*frame_dur;
	size_t		frame_count;
}	t_sprite;

t_sprite	sprite_load(void *mlx, const char *rsc_path, const char *name);
t_sprite	sprite_load_patrol(void *mlx, char *rsc_path);
t_sprite	sprite_load_player(void *mlx, char *rsc_path);
void		sprite_delete(t_sprite *sprite, void *mlx);

void		sprite_draw(t_sprite sprite, t_mlx_window win, t_pos pos);
void		sprite_draw_patrol(t_sprite sprite, t_mlx_window win, t_pos pos,
				int facing);
void		sprite_draw_player(t_sprite sprite, t_mlx_window win, t_pos pos);

char		*sprite_name_from_eid(int id);

#endif
