/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:37:58 by wdavey            #+#    #+#             */
/*   Updated: 2023/07/12 17:09:39 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*index;

	c = (char)c;
	index = NULL;
	while ('\0' != *s)
	{
		if (*s == c)
			index = s;
		s++;
	}
	if (c == *s)
		return ((char *)s);
	return ((char *)index);
}
