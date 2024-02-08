/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 07:53:01 by wdavey            #+#    #+#             */
/*   Updated: 2024/02/09 06:30:15 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "mlx.h"
#include "ft_printf.h"

#include "mlxw.h"
#include "slmap.h"
#include "gamestate.h"
#include "entity.h"

int	on_key(int keycode, t_gamewindow *gw);
int	run_turn(t_gamewindow *gw);
int	sl_close(t_gamewindow *gw);

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
	gw.win.win = mlx_new_window(gw.win.mlx, (gw.game.map.width * 32) + 640,
			(gw.game.map.height * 32) + 480, "so_long");

	gw.game = gamestate_init(gw.win, gw.game.map, rsc_path);
	gamestate_render(&gw);
	mlx_hook(gw.win.win, 17, 0, sl_close, &gw);
	mlx_key_hook(gw.win.win, on_key, &gw);
	mlx_loop_hook(gw.win.mlx, run_turn, &gw);
	mlx_loop(gw.win.mlx);
	return (0);
}
