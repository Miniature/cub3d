/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_id_from_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:28:12 by wdavey            #+#    #+#             */
/*   Updated: 2024/03/04 17:47:55 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity.h"
#include "slmap.h"

enum e_id	e_id_from_char(char c)
{
	if (c == 'N')
		return (PLAYER_NORTH);
	if (c == 'S')
		return (PLAYER_SOUTH);
	if (c == 'E')
		return (PLAYER_EAST);
	if (c == 'W')
		return (PLAYER_WEST);
	if (c == COLLECTIBLE_CHAR)
		return (COLLECTIBLE_ID);
	if (c == EXIT_CHAR)
		return (EXIT_ID);
	return (INVALID_ID);
}
