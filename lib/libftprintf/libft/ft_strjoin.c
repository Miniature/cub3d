/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:20:29 by wdavey            #+#    #+#             */
/*   Updated: 2023/07/11 17:12:31 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	char	*joined;

	if (NULL == s1 || NULL == s2)
		return (NULL);
	joined = malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(*joined));
	if (NULL == joined)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
	{
		joined[i] = *s1;
		s1++;
		i++;
	}
	while (*s2 != '\0')
	{
		joined[i] = *s2;
		i++;
		s2++;
	}
	joined[i] = '\0';
	return (joined);
}
