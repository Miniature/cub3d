/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handler_decimal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 09:30:04 by wdavey            #+#    #+#             */
/*   Updated: 2023/08/23 06:12:15 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>

#include "libft.h"

#include "ft_printf_flags.h"
#include "ft_math.h"

int		ft_putnstr_fd(char *str, size_t len, int fd);
int		ft_printf_string(char *s, t_ft_printf_flags flags, char padding);
int		ft_putnchars_fd(char c, int n, int fd);
char	*ft_strjoin_free(char *s1, char *s2, bool frees1, bool frees2);

//handles printing '0' when using 0 as padding or precision is set
//0 as padding uses field width, which includes any sign character
//norm doing heavy lifting on making my code look like shit here
ssize_t	ft_printf_decimal_pad_zeros(char *n_str, t_ft_printf_flags flags)
{
	bool	done_sign;
	int		wdh_padding;
	int		prc_padding;

	if (true == flags.pad_0 || -1 != flags.precision)
	{
		done_sign = ('-' == n_str[0] || flags.sign || flags.ssign);
		wdh_padding = (flags.width - (ft_strlen(n_str) - (n_str[0] == '-'))
				- done_sign) * (flags.pad_0 && -1 == flags.precision);
		prc_padding = flags.precision
			- (ft_strlen(n_str) - ('-' == n_str[0]));
		return (ft_putnchars_fd('0',
				ft_max(wdh_padding, prc_padding), 1));
	}
	return (0);
}

ssize_t	ft_printf_decimal_sign(char *n_str, t_ft_printf_flags flags)
{
	if ('-' == n_str[0])
		return (write(1, "-", 1));
	else if (true == flags.sign)
		return (write(1, "+", 1));
	else if (true == flags.ssign)
		return (write(1, " ", 1));
	return (0);
}

//handles all characters before digits of the number (including sign)
ssize_t	ft_printf_decimal_prefix(char *n_str, t_ft_printf_flags f)
{
	int		rval;
	size_t	total_rval;
	int		num_w;

	num_w = ft_max(f.precision + ('-' == n_str[0] || f.sign || f.ssign),
			ft_strlen(n_str) + ((f.sign || f.ssign) && ('-' != n_str[0])));
	if (true == f.pad_0 && -1 == f.precision)
		num_w = ft_max(ft_strlen(n_str) + ((f.sign || f.ssign)
					&& ('-' != n_str[0])), f.width);
	rval = 0;
	total_rval = 0;
	if (false == f.left)
		rval = ft_putnchars_fd(' ', f.width - num_w, 1);
	if (0 > rval)
		return (-1);
	total_rval += rval;
	rval = ft_printf_decimal_sign(n_str, f);
	if (0 > rval)
		return (-1);
	total_rval += rval;
	rval = ft_printf_decimal_pad_zeros(n_str, f);
	if (0 > rval)
		return (-1);
	return (total_rval + rval);
}

ssize_t	ft_printf_decimal_merged(char *n_str, t_ft_printf_flags flags)
{
	int		rval;
	ssize_t	total_rval;

	if (NULL == n_str)
		return (-1);
	rval = 0;
	if ('0' == n_str[0] && 0 == flags.precision)
		n_str[0] = '\0';
	total_rval = ft_printf_decimal_prefix(n_str, flags);
	if (0 > total_rval)
		return (-1);
	rval = ft_putnstr_fd(n_str + (n_str[0] == '-'), -1, 1);
	if (0 > rval)
		return (-1);
	total_rval += rval;
	if (total_rval < flags.width && flags.left)
	{
		rval = ft_putnchars_fd(' ', flags.width - total_rval, 1);
		if (0 > rval)
			return (-1);
		total_rval += rval;
	}
	return (total_rval);
}
