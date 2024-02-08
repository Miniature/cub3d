/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slmap_get_block.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:03:38 by ihogben           #+#    #+#             */
/*   Updated: 2024/02/08 14:03:46 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slmap.h"

#include <stdlib.h>

//takes an x and y input and returns the map data at that position
char	slmap_get_block(t_slmap map, int x, int y)
{
	return (map.raw[x][y]);
}
