/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slmap.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:26:20 by wdavey            #+#    #+#             */
/*   Updated: 2024/02/01 16:02:37 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SLMAP_H
# define SLMAP_H

# include <stddef.h>

# define WALL_CHAR 49 //'1'
# define FLOOR_CHAR 48 //'0'
# define PLAYER_CHAR 80 //'P'
# define EXIT_CHAR 69 //'E'
# define COLLECTIBLE_CHAR 67 //'C'
# define PATROL_CHAR 72 //'H'

typedef struct s_slmap
{
	char	**raw;
	size_t	width; //minmap size
	size_t	height;
}	t_slmap;

t_slmap	slmap_load(char *map_path);
void	slmap_delete(t_slmap slmap);
void	slmap_free(t_slmap *slmap);

char	slmap_get_block(t_slmap slmap, int x, int y);
#endif
