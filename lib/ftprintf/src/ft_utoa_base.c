/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:30:54 by wdavey            #+#    #+#             */
/*   Updated: 2023/08/17 19:28:32 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "libft.h"

#include "ft_printf_flags.h"
#include "ft_math.h"

static void	ft_strrev(char *s)
{
	size_t	sl;
	size_t	si;
	char	t;

	sl = ft_strlen(s);
	si = 0;
	while (si < sl / 2)
	{
		t = s[si];
		s[si] = s[sl - 1 - si];
		s[sl - 1 - si] = t;
		si++;
	}
}

static size_t	num_digits(unsigned long n, size_t base_len)
{
	size_t	d;

	if (0 == n)
		return (1);
	d = 0;
	while (n != 0)
	{
		d++;
		n /= base_len;
	}
	return (d);
}

char	*ft_utoa_base(unsigned long n, const char *base)
{
	char	*s;
	size_t	i;

	s = malloc(num_digits(n, ft_strlen(base)) + 1 * sizeof(*s));
	if (NULL == s)
		return (NULL);
	i = 0;
	if (0 == n)
		s[i++] = '0';
	while (n)
	{
		s[i++] = base[n % ft_strlen(base)];
		n /= ft_strlen(base);
	}
	s[i] = 0;
	ft_strrev(s);
	return (s);
}

char	*ft_utoa(unsigned long n)
{
	return (ft_utoa_base(n, "0123456789"));
}
