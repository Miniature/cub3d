/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxw_colour.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:58:48 by wdavey            #+#    #+#             */
/*   Updated: 2023/08/30 16:18:48 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxw.h"

t_colour	mlxw_argb(unsigned char a, unsigned char r,
	unsigned char g, unsigned char b)
{
	return ((t_colour)(a << 24 | r << 16 | g << 8 | b));
}

t_colour	mlxw_rgb(unsigned char r,
	unsigned char g, unsigned char b)
{
	return ((t_colour)(r << 16 | g << 8 | b));
}
