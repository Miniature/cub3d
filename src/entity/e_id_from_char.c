/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_id_from_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:28:12 by wdavey            #+#    #+#             */
/*   Updated: 2023/09/02 12:30:45 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity.h"
#include "slmap.h"

enum e_id	e_id_from_char(char c)
{
	if (c == PLAYER_CHAR)
		return (PLAYER_ID);
	if (c == PATROL_CHAR)
		return (PATROL_ID);
	if (c == COLLECTIBLE_CHAR)
		return (COLLECTIBLE_ID);
	if (c == EXIT_CHAR)
		return (EXIT_ID);
	return (INVALID_ID);
}
