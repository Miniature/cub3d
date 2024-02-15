/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_perspective_init.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:52:32 by ihogben           #+#    #+#             */
/*   Updated: 2024/02/14 13:52:33 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include <stdio.h>
#include <stdlib.h>

t_gamestate_perspective *raycasting_perspective_init()
{
	t_gamestate_perspective *p = 
				(t_gamestate_perspective *)malloc(sizeof(t_gamestate_perspective));
	p->plane_x = 0.66; //should be initialized depending on spawn direction
	p->plane_y = 0;// currently defaulting to norths
	return (p);
}