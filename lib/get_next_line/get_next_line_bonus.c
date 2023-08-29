/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:51:50 by wdavey            #+#    #+#             */
/*   Updated: 2023/08/29 16:33:26 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

char				*gnl_strnstr(const char *h, const char *n, size_t len);
char				*gnl_substr(const char *s, size_t start, size_t len);
char				*gnl_strjoin_f(char *s1, char *s2);

//zeroes buffer
static void	clear_buffer(char *buffer, ssize_t buf_len)
{
	if (0 > buf_len)
		return ;
	while (0 < buf_len--)
	{
		buffer[buf_len] = 0;
	}
}

//loads next section of fd
static ssize_t	read_next(int fd, char *buf)
{
	int	read_value;

	read_value = read(fd, buf, BUFFER_SIZE);
	if (0 >= read_value)
	{
		clear_buffer(buf, BUFFER_SIZE);
		return (read_value);
	}
	else
	{
		clear_buffer(buf + read_value, BUFFER_SIZE - read_value);
	}
	return (read_value);
}

//returns index of first non-null character in buffer or -1 on error
//if not initially found tries reading once
static ssize_t	find_start(int fd, char	*buffer, size_t buf_size)
{
	size_t	start;
	ssize_t	read_value;

	start = 0;
	if (NULL == buffer)
		return (-1);
	while ('\0' == buffer[start] && start < buf_size)
		start++;
	if (buf_size == start)
	{
		read_value = read_next(fd, buffer);
		if (0 > read_value)
			return (-1);
		return (0);
	}
	return (start);
}

#define BUF_SIZ BUFFER_SIZE
#define BUFFER_COUNT 1024

//buffer is BUFFER_SIZE + 1 to make the buffer be a true c-string
//to make it easier to manipulate with string functions (mostly strlen)
typedef struct s_fd_buffer {
	int		fd;
	char	buffer[BUFFER_SIZE + 1];
}	t_fd_buffer;

//returns buffer used for fd
static char	*get_fd_buffer(int fd)
{
	static t_fd_buffer	bufs[BUFFER_COUNT];
	size_t				i_bufs;

	i_bufs = 0;
	while (bufs[i_bufs].fd != fd && 0 != bufs[i_bufs].fd)
	{
		i_bufs++;
	}
	bufs[i_bufs].fd = fd;
	return (bufs[i_bufs].buffer);
}

typedef struct s_gnl_vars {
	ssize_t	s;
	ssize_t	read_value;
	char	*b;
	char	*nlp;
	char	*rv;
}	t_gnl_vars;

//totally not obfuscated i promise
//v.b = the buffer for fd
//v.nlp = position of the first '\n'
//v.rv = the currently found part of the next line (return value)
//v.s = offset of first unread part of the buffer (0 if fresh buffer)
//v.read_value = return value of read()
char	*get_next_line(int fd)
{
	t_gnl_vars	v;

	v.b = get_fd_buffer(fd);
	v.s = find_start(fd, v.b, BUFFER_SIZE);
	if (-1 == v.s || '\0' == v.b[v.s])
		return (NULL);
	v.rv = NULL;
	v.nlp = gnl_strnstr(v.b + v.s, "\n", BUFFER_SIZE - v.s);
	while (NULL == v.nlp)
	{
		v.rv = gnl_strjoin_f(v.rv, gnl_substr(v.b + v.s, 0, BUF_SIZ - v.s + 1));
		v.read_value = read_next(fd, v.b);
		v.s = 0;
		if (0 == v.read_value)
			break ;
		if (-1 == v.read_value)
		{
			free(v.rv);
			return (NULL);
		}
		v.nlp = gnl_strnstr(v.b, "\n", BUFFER_SIZE);
	}
	v.rv = gnl_strjoin_f(v.rv, gnl_substr(v.b + v.s, 0, v.nlp - v.b - v.s + 1));
	clear_buffer(v.b, (v.nlp - v.b) + 1);
	return (v.rv);
}
