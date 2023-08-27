/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:01:04 by wdavey            #+#    #+#             */
/*   Updated: 2023/07/11 17:11:09 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(const char *s, int fd);

void	ft_putendl_fd(const char *s, int fd)
{
	if (NULL == s)
		return ;
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
