/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 07:53:01 by wdavey            #+#    #+#             */
/*   Updated: 2023/08/31 11:36:55 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "mlx.h"
#include "ft_printf.h"

#include "mlxw.h"
#include "slmap.h"
#include "gamestate.h"

int	error(char *msg)
{
	ft_printf("Error\n%s\n", msg);
	exit(1);
	return (1);
}

int	sl_close(void)
{
	exit(0);
	return (0);
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
	t_mlx_window	window;
	t_slmap			map;
	t_gamestate		state;
	char			*rsc_path;

	if (2 != argc)
		error("incorrect args (expected only path to map)");
	map = slmap_load(argv[1]);
	rsc_path = get_rsc_path(argv[0]);
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, map.width * 32, map.height * 32,
			"window");
	state = gamestate_init(window, map, rsc_path);
	gamestate_render(state, window);
	mlx_hook(window.win, 17, 0, sl_close, NULL);
	mlx_loop(window.mlx);
	return (0);
}
