/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:51:50 by wdavey            #+#    #+#             */
/*   Updated: 2023/07/19 16:44:15 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char				*ft_strnstr(const char *h, const char *n, size_t len);
char				*ft_substr(const char *s, size_t start, size_t len);
char				*ft_strjoin_free(char *s1, char *s2);

void	clear_buffer(char *buffer, ssize_t buf_len)
{
	if (0 > buf_len)
		return ;
	while (0 < buf_len--)
	{
		buffer[buf_len] = 0;
	}
}

ssize_t	read_next(int fd, char *buf)
{
	int	a;

	clear_buffer(buf, BUFFER_SIZE);
	a = read(fd, buf, BUFFER_SIZE);
	if (0 >= a)
	{
		clear_buffer(buf, BUFFER_SIZE);
		return (a);
	}
	return (a);
}

size_t	find_start(int fd, char	*buffer)
{
	size_t	start;

	start = 0;
	while ('\0' == buffer[start] && start < BUFFER_SIZE)
		start++;
	if (BUFFER_SIZE == start)
	{
		read_next(fd, buffer);
		return (0);
	}
	return (start);
}

char	*ft_free(char **p)
{
	if (NULL != *p)
		free(*p);
	*p = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	b[BUFFER_SIZE + 1];
	size_t		s;
	char		*seg_end;
	char		*line;
	ssize_t		read_value;

	s = find_start(fd, b);
	if ('\0' == b[s])
		return (NULL);
	line = NULL;
	seg_end = ft_strnstr(b + s, "\n", BUFFER_SIZE - s);
	while (NULL == seg_end)
	{
		line = ft_strjoin_free(line, ft_substr(b + s, 0, BUFFER_SIZE - s + 1));
		read_value = read_next(fd, b);
		s = 0;
		if (0 == read_value)
			break ;
		if (-1 == read_value)
			return (ft_free(&line));
		seg_end = ft_strnstr(b, "\n", BUFFER_SIZE);
	}
	line = ft_strjoin_free(line, ft_substr(b + s, 0, seg_end - b - s + 1));
	clear_buffer(b, (seg_end - b) + 1);
	return (line);
}
