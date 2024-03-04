/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamestate_init_config.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:20:22 by wdavey            #+#    #+#             */
/*   Updated: 2024/03/04 17:34:13 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gamestate.h"

void	gamestate_init_config(t_gamestate *state, char *rsc_path)
{
	(void)rsc_path;
	state->wall_img[NORTH] = state->terrain; //temp all walls copy terrain
	state->wall_img[SOUTH] = state->terrain;
	state->wall_img[EAST] = state->terrain;
	state->wall_img[WEST] = state->terrain;
}
