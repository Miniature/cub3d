/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handler_hex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 20:12:06 by wdavey            #+#    #+#             */
/*   Updated: 2023/08/22 11:26:51 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#include "libft.h"

#include "ft_math.h"
#include "ft_printf_flags.h"

char	*ft_utoa_base(unsigned long n, const char *base);
int		ft_putnchars_fd(char c, int n, int fd);
int		ft_putnstr_fd(char *str, size_t len, int fd);

ssize_t	ft_printf_hex_pre(char *n_str, t_ft_printf_flags flags)
{
	long	spaces;

	if (false == flags.left)
	{
		spaces = ft_umax(ft_strlen(n_str), flags.precision);
		spaces = flags.width - ft_max(ft_strlen(n_str), flags.precision);
		if (false != flags.alt && '0' != n_str[0] && '\0' != n_str[0])
			spaces -= 2;
		if (true == flags.pad_0 && -1 == flags.precision)
			spaces = 0;
		return (ft_putnchars_fd(' ', spaces, 1));
	}
	return (0);
}

ssize_t	ft_printf_hex_form(char *n_str, t_ft_printf_flags flags)
{
	if (false != flags.alt && '0' != n_str[0] && '\0' != n_str[0])
	{
		if ('X' == flags.alt)
			return (write(1, "0X", 2));
		else
			return (write(1, "0x", 2));
	}
	return (0);
}

ssize_t	ft_printf_hex_zeros(char *n_str, t_ft_printf_flags flags)
{
	if (true == flags.pad_0 && -1 == flags.precision)
		return (ft_putnchars_fd('0', ft_max(flags.precision - ft_strlen(n_str),
					flags.width - ft_strlen(n_str)) - (2 * (false != flags.alt
						&& '0' != n_str[0] && '\0' != n_str[0])), 1));
	else
		return (ft_putnchars_fd('0', flags.precision - ft_strlen(n_str), 1));
}

ssize_t	ft_printf_hex_post(size_t printed, t_ft_printf_flags flags)
{
	if (true == flags.left)
	{
		return (ft_putnchars_fd(' ', flags.width - printed, 1));
	}
	return (0);
}

ssize_t	ft_printf_hex(char *n_str, t_ft_printf_flags flags)
{
	ssize_t	rval;
	size_t	total_rval;

	rval = ft_printf_hex_pre(n_str, flags);
	if (0 > rval)
		return (-1);
	total_rval = rval;
	rval = ft_printf_hex_form(n_str, flags);
	if (0 > rval)
		return (-1);
	total_rval += rval;
	rval = ft_printf_hex_zeros(n_str, flags);
	if (0 > rval)
		return (-1);
	total_rval += rval;
	rval = ft_putnstr_fd(n_str, -1, 1);
	if (0 > rval)
		return (-1);
	total_rval += rval;
	rval = ft_printf_hex_post(total_rval, flags);
	if (0 > rval)
		return (-1);
	return (total_rval + rval);
}
