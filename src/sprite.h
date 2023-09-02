/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:45:33 by wdavey            #+#    #+#             */
/*   Updated: 2023/09/02 13:00:17 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include <stddef.h>

# include "mlxw.h"
# include "utils.h"

typedef struct s_sprite {
	t_mlx_image	*frames;
	float		*frame_dur;
	size_t		frame_count;
}	t_sprite;

t_sprite	sprite_load(void *mlx, const char *rsc_path, const char *name);
void		sprite_delete(t_sprite *sprite, void *mlx);

void		sprite_draw(t_sprite sprite, t_mlx_window win, t_pos pos);

char		*sprite_name_from_eid(int id);

#endif
