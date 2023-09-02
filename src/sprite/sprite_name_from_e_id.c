/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_name_from_e_id.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:29:03 by wdavey            #+#    #+#             */
/*   Updated: 2023/09/02 12:32:14 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity.h"

char	*sprite_name_from_eid(int id)
{
	if (PLAYER_ID == id)
		return ("cleanbot1.xpm");
	if (PATROL_ID == id)
		return ("secbox_s.xpm");
	if (COLLECTIBLE_ID == id)
		return ("dirt.xpm");
	if (EXIT_ID == id)
		return ("charger.xpm");
	error("tried to get sprite for invalid entity id");
	return (NULL);
}
