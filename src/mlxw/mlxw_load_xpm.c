/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxw_load_xpm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:30:40 by wdavey            #+#    #+#             */
/*   Updated: 2023/08/30 13:46:02 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "mlxw.h"

//i hate minilibx
t_mlx_image	mlxw_load_xpm(void *mlx, char *path)
{
	t_mlx_image	img;

	img.img = mlx_xpm_file_to_image(mlx, path, &(img.w), &(img.h));
	return (img);
}
