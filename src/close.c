/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:48:39 by wdavey            #+#    #+#             */
/*   Updated: 2023/09/04 12:19:38 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "gamestate.h"

int	sl_close(t_gamewindow *gw)
{
	gamestate_destroy(gw->game, gw->win);
	exit(0);
	return (0);
}
