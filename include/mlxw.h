/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:43:28 by wdavey            #+#    #+#             */
/*   Updated: 2024/02/01 16:02:28 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//MLX Wrapper
#ifndef MLXW_H
# define MLXW_H

# include <stddef.h>

# include "utils.h"

typedef struct s_mlx_window
{
	void	*mlx;
	void	*win;
}	t_mlx_window;

typedef struct s_mlx_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		w;
	int		h;
}	t_mlx_image;

typedef union colour
{
	int	colour;
	int	c;
	struct
	{
		unsigned char	a;
		unsigned char	r;
		unsigned char	g;
		unsigned char	b;
	};
}	t_colour;

t_colour		mlxw_argb(unsigned char a, unsigned char r,
					unsigned char g, unsigned char b);
t_colour		mlxw_rgb(unsigned char r,
					unsigned char g, unsigned char b);

t_mlx_image		mlxw_new_image(void *mlx, size_t width, size_t height);
t_mlx_image		mlxw_load_png(void *mlx, char *name);
t_mlx_image		mlxw_load_xpm(void *mlx, char *name);
void			mlxw_destroy_image(t_mlx_image img, void *mlx);

t_mlx_image		mlxw_image_overlay(t_mlx_image dst, t_mlx_image src, t_pos p);

int				mlxw_draw(t_mlx_window win, t_mlx_image image, t_pos pos);
void			mlxw_draw_string(t_mlx_window win, char *str, t_pos pos,
					t_colour colour);

#endif
