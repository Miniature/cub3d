/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxw_destroy_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:48:43 by wdavey            #+#    #+#             */
/*   Updated: 2023/08/31 12:37:58 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "mlxw.h"

void	mlxw_destroy_image(t_mlx_image img, void *mlx)
{
	if (NULL != img.img)
	{
		mlx_destroy_image(mlx, img.img);
		img.img = NULL;
	}
}
