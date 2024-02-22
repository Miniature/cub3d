/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamestate_init_background.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:35:54 by ihogben           #+#    #+#             */
/*   Updated: 2024/02/14 16:35:57 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "mlxw.h"
#include "slmap.h"
#include "sprite.h"
#include "gamestate.h"

t_mlx_image	gamestate_init_background(t_mlx_window window)
{
	t_mlx_image	image;

	image = mlxw_new_image(window.mlx, DISPLAY_WIDTH, DISPLAY_HEIGHT);
	return (image);
}
