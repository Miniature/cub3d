/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slmap_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:29:15 by wdavey            #+#    #+#             */
/*   Updated: 2023/09/04 13:28:20 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slmap.h"

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "utils.h"

t_list	*get_all_lines(char	*path)
{
	int		fd;
	t_list	*lines;
	char	*line;

	lines = NULL;
	fd = open(path, O_RDONLY);
	if (0 >= fd)
		error("failed to open map file");
	line = get_next_line(fd);
	while (NULL != line)
	{
		line[ft_strlen(line) - 1] = '\0';
		ft_lstadd_back(&lines, ft_lstnew(line));
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

void	slmap_load_copy_lines(t_slmap *map, t_list *lines)
{
	size_t	it;
	t_list	*lines_it;

	lines_it = lines;
	it = 0;
	while (lines_it && (lines_it->next || ft_strncmp(lines_it->content, "", 2)))
	{
		map->raw[it++] = lines_it->content;
		lines = lines_it;
		lines_it = lines_it->next;
		free(lines);
	}
}

t_slmap	slmap_load(char	*map_path)
{
	t_list	*lines;
	t_slmap	slmap;

	if (NULL == map_path || !ft_strnstr(map_path, ".ber", ft_strlen(map_path)))
	{
		error("file is not a .ber map");
	}
	lines = get_all_lines(map_path);
	slmap.width = ft_strlen(lines->content);
	slmap.height = ft_lstsize(lines)
		- (0 == ft_strncmp(ft_lstlast(lines)->content, "", 2));
	slmap.raw = malloc(slmap.height * sizeof(*(slmap.raw)));
	slmap_load_copy_lines(&slmap, lines);
	return (slmap);
}
