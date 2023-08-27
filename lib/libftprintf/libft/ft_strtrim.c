/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:24:57 by wdavey            #+#    #+#             */
/*   Updated: 2023/07/12 13:51:49 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);

static bool	ft_strcontains(const char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (true);
		str++;
	}
	return (false);
}

static const char	*find_start(const char *s, const char *set)
{
	while (ft_strcontains(set, *s))
		s++;
	return (s);
}

static const char	*find_end(const char *s, const char *set)
{
	const char	*end = s;

	while (*end)
		end++;
	end--;
	while (end >= s && ft_strcontains(set, *end))
		end--;
	return (end);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char		*trim;
	const char	*s_start;
	const char	*s_end;
	int			i;

	if (NULL == s1 || NULL == set)
		return (NULL);
	s_start = find_start(s1, set);
	s_end = find_end(s_start, set);
	trim = malloc((s_end - s_start + 2) * sizeof(*trim));
	if (NULL == trim)
		return (NULL);
	i = 0;
	while (i <= s_end - s_start)
	{
		trim[i] = s_start[i];
		i++;
	}
	trim[i] = '\0';
	return (trim);
}
