/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:09:02 by wdavey            #+#    #+#             */
/*   Updated: 2023/08/15 21:15:20 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putnchars_fd(char c, int n, int fd)
{
	int	count;

	count = 0;
	while (n > count)
	{
		if (0 > write(fd, &c, 1))
			return (-1);
		count++;
	}
	return (count);
}
