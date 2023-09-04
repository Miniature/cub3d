/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxw_draw_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:48:41 by wdavey            #+#    #+#             */
/*   Updated: 2023/09/04 12:50:45 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "mlxw.h"

void	mlxw_draw_string(t_mlx_window win, char *str, t_pos pos,
			t_colour colour)
{
	mlx_string_put(win.mlx, win.win, pos.x, pos.y, colour.colour, str);
}
