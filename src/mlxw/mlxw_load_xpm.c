/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxw_load_xpm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:30:40 by wdavey            #+#    #+#             */
/*   Updated: 2024/03/04 19:42:59 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "mlxw.h"

//i hate minilibx
t_mlx_image	mlxw_load_xpm(void *mlx, char *path)
{
	t_mlx_image	img;

	img.img = mlx_xpm_file_to_image(mlx, path, &(img.w), &(img.h));
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	return (img);
}
