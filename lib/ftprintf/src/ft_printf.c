/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:25:47 by wdavey            #+#    #+#             */
/*   Updated: 2023/08/22 10:04:02 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#include "ft_printf.h"
#include "libft.h"
#include "ft_printf_flags.h"

ssize_t						ft_printf_char(char c,
								t_ft_printf_flags flags);
ssize_t						ft_printf_string(char *s,
								t_ft_printf_flags flags, char padding);
ssize_t						ft_printf_decimal(int d,
								t_ft_printf_flags flags);
ssize_t						ft_printf_unsigned_decimal(unsigned int d,
								t_ft_printf_flags flags);
ssize_t						ft_printf_pointer(const void *p,
								t_ft_printf_flags flags);
ssize_t						ft_printf_hex_lower(int x,
								t_ft_printf_flags flags);
ssize_t						ft_printf_hex_upper(int x,
								t_ft_printf_flags flags);

static int					ft_printf_run(const char **fstr, va_list *args);
static t_ft_printf_flags	ft_printf_gather_options(const char **fstr);

static t_ft_printf_flags	ft_printf_gather_flags(const char **fstr)
{
	t_ft_printf_flags	flags;

	ft_memset(&flags, 0, sizeof(flags));
	while (true)
	{
		if ('#' == **fstr)
			flags.alt = true;
		else if ('-' == **fstr)
			flags.left = true;
		else if ('+' == **fstr)
			flags.sign = true;
		else if (' ' == **fstr)
			flags.ssign = true;
		else if ('0' == **fstr)
			flags.pad_0 = true;
		else
			break ;
		(*fstr)++;
	}
	return (flags);
}

static t_ft_printf_flags	ft_printf_gather_options(const char **fstr)
{
	t_ft_printf_flags	flags;

	flags = ft_printf_gather_flags(fstr);
	if (ft_isdigit(**fstr))
	{
		flags.width = ft_atoi(*fstr);
		while (ft_isdigit(**fstr))
			(*fstr)++;
	}
	flags.precision = -1;
	if ('.' == **fstr && (*fstr)++)
	{
		flags.precision = ft_atoi(*fstr);
		while (ft_isdigit(**fstr))
			(*fstr)++;
	}
	return (flags);
}

static int	ft_printf_handle_arg(const char **fstr, va_list *args,
	t_ft_printf_flags flags)
{
	if ('c' == **fstr)
		return (ft_printf_char((char)va_arg(*args, int), flags));
	else if ('s' == **fstr)
		return (ft_printf_string(va_arg(*args, char *), flags, ' '));
	else if ('p' == **fstr)
		return (ft_printf_pointer(va_arg(*args, void *), flags));
	else if ('d' == **fstr || 'i' == **fstr)
		return (ft_printf_decimal(va_arg(*args, int), flags));
	else if ('u' == **fstr)
		return (ft_printf_unsigned_decimal(va_arg(*args, unsigned int), flags));
	else if ('x' == **fstr)
		return (ft_printf_hex_lower(va_arg(*args, unsigned int), flags));
	else if ('X' == **fstr)
		return (ft_printf_hex_upper(va_arg(*args, unsigned int), flags));
	else if ('%' == **fstr)
		return (ft_printf_string("%", flags, ' '));
	return (0);
}

int	ft_printf(const char *fstr, ...)
{
	va_list	args;
	int		print_count;
	int		last_write;

	if (NULL == fstr)
		return (0);
	va_start(args, fstr);
	print_count = 0;
	while (*fstr)
	{
		last_write = ft_printf_run(&fstr, &args);
		if (0 > last_write)
		{
			print_count = -1;
			break ;
		}
		print_count += last_write;
		fstr++;
	}
	va_end(args);
	return (print_count);
}

static int	ft_printf_run(const char **fstr, va_list *args)
{
	t_ft_printf_flags	flags;

	if ('%' == **fstr)
	{
		(*fstr)++;
		flags = ft_printf_gather_options(fstr);
		return (ft_printf_handle_arg(fstr, args, flags));
	}
	else
	{
		if (0 > write(1, *fstr, 1))
			return (-1);
		return (1);
	}
}
