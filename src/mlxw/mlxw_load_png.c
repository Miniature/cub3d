/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxw_load_png.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:30:40 by wdavey            #+#    #+#             */
/*   Updated: 2024/02/01 16:04:26 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "mlxw.h"

t_mlx_image	mlxw_load_png(void *mlx, char *path)
{
	t_mlx_image	img;

	img.img = mlx_png_file_to_image(mlx, path, &(img.w), &(img.h));
	return (img);
}
