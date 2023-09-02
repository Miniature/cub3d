/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handler_string.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 22:10:34 by wdavey            #+#    #+#             */
/*   Updated: 2023/08/23 06:11:29 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>

#include "libft.h"

#include "ft_printf_flags.h"
#include "ft_math.h"

int	ft_putnstr_fd(char *str, size_t len, int fd);
int	ft_putnchars_fd(char c, size_t n, int fd);

ssize_t	ft_printf_string(char *s, t_ft_printf_flags flags, char padding)
{
	int	rval;
	int	to_print;

	if (NULL == s)
		s = "(null)";
	to_print = ft_umin(ft_strlen(s), flags.precision);
	rval = 0;
	if (false == flags.left && to_print < flags.width)
		rval += ft_putnchars_fd(padding, flags.width - to_print, 1);
	if (0 > rval)
		return (-1);
	rval += ft_putnstr_fd(s, to_print, 1);
	if (to_print > rval)
		return (-1);
	if (true == flags.left && to_print < flags.width)
		rval += ft_putnchars_fd(padding, flags.width - to_print, 1);
	if (to_print > rval)
		return (-1);
	return (rval);
}

ssize_t	ft_printf_char(char c, t_ft_printf_flags flags)
{
	int	rval;

	rval = 0;
	if (false == flags.left && 1 < flags.width)
		rval += ft_putnchars_fd(' ', flags.width - 1, 1);
	if (0 > rval)
		return (-1);
	rval += write(1, &c, 1);
	if (1 > rval)
		return (-1);
	if (true == flags.left && 1 < flags.width)
		rval += ft_putnchars_fd(' ', flags.width - 1, 1);
	if (1 > rval)
		return (-1);
	return (rval);
}
