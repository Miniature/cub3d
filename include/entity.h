/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:41:45 by wdavey            #+#    #+#             */
/*   Updated: 2023/08/31 10:18:22 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_H
# define ENTITY_H

# include "mlxw.h"
# include "utils.h"
# include "sprite.h"

//INVALID_ID must be the last entry and NONE_ID must be the 0th
enum e_id {
	NONE_ID = 0,
	PLAYER_ID,
	PATROL_ID,
	COLLECTIBLE_ID,
	EXIT_ID,
	INVALID_ID
};

typedef struct s_entity {
	enum e_id	type;
	t_pos		pos;
	t_sprite	*sprite;
}	t_entity;

t_entity	entity_create(enum e_id id, int x, int y, t_sprite *sprite);
void		entity_draw(t_entity e, t_mlx_window w);

#endif
