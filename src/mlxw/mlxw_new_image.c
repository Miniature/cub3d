/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxw_new_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:42:25 by wdavey            #+#    #+#             */
/*   Updated: 2023/08/30 14:43:28 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "mlx.h"

#include "mlxw.h"

t_mlx_image	mlxw_new_image(void *mlx, size_t width, size_t height)
{
	t_mlx_image	new;

	new.img = mlx_new_image(mlx, width, height);
	new.w = width;
	new.h = height;
	return (new);
}
