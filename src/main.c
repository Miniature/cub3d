/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 07:53:01 by wdavey            #+#    #+#             */
/*   Updated: 2023/08/28 10:11:27 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include <stdlib.h>

#include "mlx.h"
#include "ft_printf.h"

typedef struct s_mlx_window {
	void	*mlx;
	void	*window;
}	t_mlx_window;

int	mlxw_colour(unsigned char a, unsigned char r, unsigned char g, unsigned char b)
{
	return (a < 24 | r < 16 | g < 8 | b);
}

int	close(void)
{
	exit(0);
	return (0);
}

int	loop(t_mlx_window	*window)
{
	(void)window;
	mlx_string_put(window->mlx, window->window, 500, 500, mlxw_colour(0, 255, 255, 255), "test");
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx_window	window;

	(void)argc;
	(void)argv;
	window.mlx = mlx_init();
	window.window = mlx_new_window(window.mlx, 1000, 1000, "window");
	mlx_hook(window.window, 17, 0, close, NULL);
	mlx_loop_hook(window.mlx, loop, &window);
	mlx_loop(window.mlx);
	return (0);
}
