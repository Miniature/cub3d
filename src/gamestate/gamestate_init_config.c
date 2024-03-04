/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamestate_init_config.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:20:22 by wdavey            #+#    #+#             */
/*   Updated: 2024/03/04 19:56:08 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gamestate.h"

static int	str_to_mapimgdefi(char *str)
{
	if (ft_strlen(str) > 2)
	{
		if (0 == ft_strncmp(str, "NO ", 3))
			return (0);
		if (0 == ft_strncmp(str, "SO ", 3))
			return (1);
		if (0 == ft_strncmp(str, "EA ", 3))
			return (2);
		if (0 == ft_strncmp(str, "WE ", 3))
			return (3);
		if (0 == ft_strncmp(str, "F ", 2))
			return (4);
		if (0 == ft_strncmp(str, "C ", 2))
			return (5);
	}
	return (-1);
}

static t_colour	str_to_colour(char *str)
{
	size_t		iii;
	size_t		parts;

	iii = 0;
	parts = 0;
	while (ft_isalnum(str[iii]) && !ft_isalpha(str[iii]))
		iii++;
	if (str[iii] != ',')
		error("invalid colour");
	iii++;
	while (ft_isalnum(str[iii]) && !ft_isalpha(str[iii]))
		iii++;
	if (str[iii] != ',')
		error("invalid colour");
	iii++;
	while (ft_isalnum(str[iii]) && !ft_isalpha(str[iii]))
		iii++;
	if (str[iii] != '\0')
		error("invalid colour");
	return (mlxw_rgb(ft_atoi(str), ft_atoi(ft_strchr(str, ',') + 1),
			ft_atoi(ft_strrchr(str, ',') + 1)));
}

static void	gamestate_init_config_load(t_gamestate *state, void *mlx,
		char *rsc_path, char **mapimgdefstr)
{
	if (!(mapimgdefstr[0] && mapimgdefstr[1] && mapimgdefstr[2]
			&& mapimgdefstr[3]))
		error("missing wall definition");
	if (!(mapimgdefstr[4]))
		error("missing floor definition");
	if (!(mapimgdefstr[5]))
		error("missing ceiling definition");
	state->wall_img[NORTH]
		= sprite_load(mlx, rsc_path, mapimgdefstr[0] + 3).frames[0];
	state->wall_img[SOUTH]
		= sprite_load(mlx, rsc_path, mapimgdefstr[1] + 3).frames[0];
	state->wall_img[EAST]
		= sprite_load(mlx, rsc_path, mapimgdefstr[2] + 3).frames[0];
	state->wall_img[WEST]
		= sprite_load(mlx, rsc_path, mapimgdefstr[3] + 3).frames[0];
	state->floor_colour = str_to_colour(mapimgdefstr[4] + 2);
	state->ceiling_colour = str_to_colour(mapimgdefstr[5] + 2);
}

size_t	gamestate_init_config(t_gamestate *state, void *mlx, char *rsc_path)
{
	size_t	iii;
	size_t	found;
	char	*mapimgdefstr[6];

	ft_memset(&mapimgdefstr, 0, sizeof(mapimgdefstr));
	found = 0;
	iii = -1;
	while (NULL != state->map.raw[++iii])
	{
		if (0 <= str_to_mapimgdefi(state->map.raw[iii]))
		{
			if (NULL != mapimgdefstr[str_to_mapimgdefi(state->map.raw[iii])])
				error("duplicate terrain definition");
			mapimgdefstr[str_to_mapimgdefi(state->map.raw[iii])]
				= state->map.raw[iii];
			found++;
			if (6 == found)
				break ;
		}
	}
	gamestate_init_config_load(state, mlx, rsc_path, mapimgdefstr);
	return (iii);
}
