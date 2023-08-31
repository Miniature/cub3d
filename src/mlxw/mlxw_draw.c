/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxw_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 09:53:50 by wdavey            #+#    #+#             */
/*   Updated: 2023/08/31 09:54:41 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "mlxw.h"

int	mlxw_draw(t_mlx_window win, t_mlx_image image, t_pos pos)
{
	return (mlx_put_image_to_window(win.mlx, win.win, image.img, pos.x, pos.y));
}
