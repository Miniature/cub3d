/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 07:53:01 by wdavey            #+#    #+#             */
/*   Updated: 2024/02/01 13:42:34 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "mlx.h"
#include "ft_printf.h"

#include "mlxw.h"
#include "slmap.h"
#include "gamestate.h"
#include "entity.h"

int	run_turn(int keycode, t_gamewindow *gw);
int	sl_close(t_gamewindow *gw);

int	error(char *msg)
{
	printf("Error\n%s\n", msg);
	exit(1);
	return (1);
}

char	*get_rsc_path(const char *exe_path)
{
	char	*exe_folder;
	char	*rsc_path;

	exe_folder = ft_strdup(exe_path);
	*ft_strrchr(exe_folder, '/') = '\0';
	rsc_path = ft_strjoin(exe_folder, "/rsc/img/");
	free(exe_folder);
	return (rsc_path);
}

int	main(int argc, char **argv)
{
	t_gamewindow	gw;
	char			*rsc_path;

	if (2 != argc)
		error("incorrect args (expected only path to map)");
	rsc_path = get_rsc_path(argv[0]);
	gw.game.map = slmap_load(argv[1]);
	gw.win.mlx = mlx_init();
	gw.win.win = mlx_new_window(gw.win.mlx, gw.game.map.width * 32,
			gw.game.map.height * 32, "so_long");
	gw.game = gamestate_init(gw.win, gw.game.map, rsc_path);
	gamestate_render(&gw);
	mlx_hook(gw.win.win, 17, 0, sl_close, &gw);
	mlx_key_hook(gw.win.win, run_turn, &gw);
	mlx_loop_hook(gw.win.mlx, gamestate_render, &gw);
	mlx_loop(gw.win.mlx);
	return (0);
}
