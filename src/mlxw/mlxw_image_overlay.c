/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxw_image_overlay.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:05:55 by wdavey            #+#    #+#             */
/*   Updated: 2023/08/31 11:24:39 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "mlx.h"
#include "libft.h"

#include "mlxw.h"

typedef struct s_mlx_image_data {
	char	*data;
	int		bpp;
	int		line_l;
	int		endian;
}	t_mlx_image_data;

t_mlx_image	mlxw_image_overlay(t_mlx_image dst, t_mlx_image src, t_pos p)
{
	size_t				y;
	t_mlx_image_data	src_d;
	t_mlx_image_data	dst_d;

	dst_d.data = mlx_get_data_addr(dst.img,
			&(dst_d.bpp), &(dst_d.line_l), &(dst_d.endian));
	src_d.data = mlx_get_data_addr(src.img,
			&(src_d.bpp), &(src_d.line_l), &(src_d.endian));
	y = 0;
	while (y < (size_t)src.h && y + p.y < (size_t)dst.h)
	{
		ft_memcpy(dst_d.data + ((y + p.y) * dst_d.line_l)
			+ (p.x * dst_d.bpp / 8),
			src_d.data + (y * src_d.line_l),
			src_d.line_l);
		y++;
	}
	return (dst);
}

//*(dst_d.data + (y + p.y) * dst_d.line_l + (x + p.x) * dst_d.bpp / 8)
//	= *(src_d.data + y * src_d.line_l + x * src_d.bpp / 8);
