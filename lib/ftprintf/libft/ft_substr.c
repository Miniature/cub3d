/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:14:43 by wdavey            #+#    #+#             */
/*   Updated: 2023/07/12 17:28:07 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_min(size_t a, size_t b)
{
	if (a > b)
		return (b);
	return (a);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;

	if (NULL == s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		substr = malloc(1);
		if (NULL == substr)
			return (NULL);
		*substr = '\0';
		return (substr);
	}
	len = ft_min(len, ft_strlen(s + start));
	substr = malloc((len + 1) * sizeof(*substr));
	if (NULL == substr)
		return (NULL);
	substr[len] = 0;
	while (len--)
	{
		substr[len] = s[start + len];
	}
	return (substr);
}
