/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slmap_get_block.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:03:38 by ihogben           #+#    #+#             */
/*   Updated: 2024/02/26 15:31:42 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slmap.h"

#include "libft.h"
#include <stdlib.h>

//takes an x and y input and returns the map data at that position
char	slmap_get_block(t_slmap map, size_t y, size_t x)
{
	if (y >= map.height || x >= (size_t)ft_strlen(map.raw[y]))
		return ('1');
	return (map.raw[y][x]);
}
