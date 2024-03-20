/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxw_subimage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:30:28 by wdavey            #+#    #+#             */
/*   Updated: 2024/03/20 21:09:03 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "mlxw.h"
#include "mlx.h"
#include "libft.h"

t_mlx_image	mlxw_subimage(void *mlx, t_mlx_image src, t_pos origin, t_pos size)
{
	t_mlx_image	dst;
	size_t		iii;

	size.x = fmin(size.x, src.w - origin.x);
	size.y = fmin(size.y, src.h - origin.y);
	dst = mlxw_new_image(mlx, size.x, size.y);
	iii = -1;
	while (++iii < size.y)
	{
		ft_memcpy(dst.img + (int)(size.y * dst.line_len),
			src.img, size.x * dst.bpp / 8);
	}
	return (dst);
}
