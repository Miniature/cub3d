/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handlers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:01:27 by wdavey            #+#    #+#             */
/*   Updated: 2023/08/22 11:17:33 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#include "libft.h"

#include "ft_printf_flags.h"
#include "ft_math.h"

char	*ft_utoa(unsigned long n);
char	*ft_utoa_base(unsigned long n, const char *base);
int		ft_putnstr_fd(char *str, size_t len, int fd);
int		ft_printf_string(char *s, t_ft_printf_flags flags, char padding);
int		ft_putnchars_fd(char c, int n, int fd);
char	*ft_strjoin_free(char *s1, char *s2, bool frees1, bool frees2);

ssize_t	ft_printf_decimal_merged(char *n_str, t_ft_printf_flags flags);
ssize_t	ft_printf_hex(char *n_str, t_ft_printf_flags flags);

ssize_t	ft_printf_decimal(int d, t_ft_printf_flags flags)
{
	int		rval;
	char	*n_str;

	rval = 0;
	n_str = ft_itoa(d);
	if (NULL == n_str)
		return (-1);
	rval = ft_printf_decimal_merged(n_str, flags);
	free(n_str);
	return (rval);
}

ssize_t	ft_printf_unsigned_decimal(unsigned int d, t_ft_printf_flags flags)
{
	int		rval;
	char	*n_str;

	rval = 0;
	n_str = ft_utoa(d);
	if (NULL == n_str)
		return (-1);
	rval = ft_printf_decimal_merged(n_str, flags);
	free(n_str);
	return (rval);
}

ssize_t	ft_printf_pointer(const void *p, t_ft_printf_flags flags)
{
	char	*converted;
	char	*s;
	int		rval;

	converted = ft_utoa_base((unsigned long)p, "0123456789abcdef");
	if (NULL == converted)
		return (-1);
	s = ft_strjoin("0x", converted);
	free(converted);
	if (NULL == s)
		return (-1);
	rval = ft_printf_string(s, flags, ' ');
	free(s);
	if (0 > rval)
		return (-1);
	return (rval);
}

ssize_t	ft_printf_hex_lower(unsigned long x, t_ft_printf_flags flags)
{
	char	*n_str;
	ssize_t	rval;

	n_str = ft_utoa_base(x, "0123456789abcdef");
	if (NULL == n_str)
		return (-1);
	if (0 == flags.precision && 0 == x)
		n_str[0] = '\0';
	if (true == flags.alt)
		flags.alt = 'x';
	rval = ft_printf_hex(n_str, flags);
	free(n_str);
	return (rval);
}

ssize_t	ft_printf_hex_upper(unsigned long x, t_ft_printf_flags flags)
{
	char	*n_str;
	ssize_t	rval;

	n_str = ft_utoa_base(x, "0123456789ABCDEF");
	if (NULL == n_str)
		return (-1);
	if (0 == flags.precision && 0 == x)
		n_str[0] = '\0';
	if (true == flags.alt)
		flags.alt = 'X';
	rval = ft_printf_hex(n_str, flags);
	free(n_str);
	return (rval);
}
