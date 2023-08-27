/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:30:54 by wdavey            #+#    #+#             */
/*   Updated: 2023/07/11 17:32:04 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(char *s);

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

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static size_t	num_digits(int n)
{
	size_t	d;

	if (0 == n)
		return (1);
	d = 0;
	while (n != 0)
	{
		d++;
		n /= 10;
	}
	return (d);
}

char	*ft_itoa(int n)
{
	char	*s;
	size_t	i;

	s = malloc((num_digits(n) + 1 + (n < 0)) * sizeof(*s));
	if (NULL == s)
		return (NULL);
	i = 0;
	if (n < 0)
		s[i++] = '-';
	if (0 == n)
		s[i++] = '0';
	while (n)
	{
		s[i++] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	s[i] = 0;
	if (*s == '-')
		ft_strrev(s + 1);
	else
		ft_strrev(s);
	return (s);
}
