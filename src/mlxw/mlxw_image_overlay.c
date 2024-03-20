/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxw_image_overlay.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:05:55 by wdavey            #+#    #+#             */
/*   Updated: 2024/03/20 20:20:23 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <math.h>

#include "mlx.h"
#include "libft.h"

#include "mlxw.h"

/*
typedef struct s_mlx_image_data {
	char	*data;
	int		bpp;
	int		line_l;
	int		endian;
}	t_mlx_image_data;
*/

static long	min(long a, long b)
{
	if (a < b)
		return (a);
	return (b);
}

/*
t_mlx_image	mlxw_image_overlay(t_mlx_image dst, t_mlx_image src, t_pos p)
{
	size_t				y;
	t_mlx_image_data	src_d;
	t_mlx_image_data	dst_d;
	t_pos				dsti;

	dst_d.data = mlx_get_data_addr(dst.img,
			&(dst_d.bpp), &(dst_d.line_l), &(dst_d.endian));
	src_d.data = mlx_get_data_addr(src.img,
			&(src_d.bpp), &(src_d.line_l), &(src_d.endian));
	y = 0;
	while (y < (size_t)src.h && y + p.y < (size_t)dst.h)
	{
		dsti.x = (p.x * dst_d.bpp / 8);
		dsti.y = (y + p.y) * dst_d.line_l;
		ft_memcpy(dst_d.data + ((y + (int)round(p.y)) * dst_d.line_l)
			+ ((int)round(p.x) * dst_d.bpp / 8),
			src_d.data + (y * src_d.line_l),
			min(src_d.line_l, dst_d.line_l - (p.x * dst_d.bpp / 8)));
		y++;
	}
	return (dst);
}
*/

//transparency handling
static void	image_memcpy(void *d, void *s, size_t w)
{
	size_t		iii;
	t_colour	si;
	t_colour	di;
	t_colour	f;
	float		adj_alpha;

	iii = 0;
	while (iii < w)
	{
		si = *(t_colour *)(s + iii);
		di = *(t_colour *)(d + iii);
		if (si.a == 255)
			f = di;
		else if (si.a == 0)
			f = si;
		else
		{
			adj_alpha = ((255 - di.a) / 255.0f) * ((255 - si.a) / 255.0f);
			f.a = si.a + di.a * adj_alpha;
			f.r = si.r + di.r * adj_alpha;
			f.g = si.g + di.g * adj_alpha;
			f.b = si.b + di.b * adj_alpha;
		}
		*(t_colour *)(d + iii) = f;
		iii += 4;
	}
}

t_mlx_image	mlxw_image_overlay(t_mlx_image dst, t_mlx_image src, t_pos p)
{
	long	y;
	void	*dst_p;
	void	*src_p;
	t_pos	s_start;
	long	width;

	s_start.x = fmax(0, -p.x);
	s_start.y = fmax(0, -p.y);
	width = min(src.line_len - s_start.x, dst.line_len - p.x);
	if (0 > width)
		return (dst);
	y = -1;
	while (++y < src.h - (long)s_start.y && y + p.y < (long)dst.h)
	{
		dst_p = dst.addr;
		dst_p += (int)(fmax(0, p.x)) *dst.bpp / 8;
		dst_p += (int)(y + fmax(0, p.y)) *dst.line_len;
		src_p = src.addr;
		src_p += (int)(fmax(0, s_start.x)) *src.bpp / 8;
		src_p += (int)(y + fmax(0, s_start.y)) *src.line_len;
		image_memcpy(dst_p, src_p, width / 2);
	}
	return (dst);
}
