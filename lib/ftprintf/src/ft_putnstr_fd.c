/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd_rv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:36:32 by wdavey            #+#    #+#             */
/*   Updated: 2023/08/17 20:52:45 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"

#include "ft_math.h"

int	ft_putnstr_fd(char *str, size_t len, int fd)
{
	return (write(fd, str, ft_umin(ft_strlen(str), len)));
}
