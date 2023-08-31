/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slmap_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:01:06 by wdavey            #+#    #+#             */
/*   Updated: 2023/08/28 12:54:35 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slmap.h"

#include <stdlib.h>

void	slmap_delete(t_slmap slmap)
{
	size_t	it;

	it = 0;
	while (it < slmap.height)
	{
		free(slmap.raw[it]);
		it++;
	}
	free(slmap.raw);
}

void	slmap_free(t_slmap *slmap)
{
	slmap_delete(*slmap);
	free(slmap);
}
