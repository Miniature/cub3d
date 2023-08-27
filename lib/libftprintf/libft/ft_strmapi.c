/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:51:35 by wdavey            #+#    #+#             */
/*   Updated: 2023/07/11 17:20:10 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*rv;

	if (NULL == s || NULL == f)
		return (NULL);
	rv = malloc((ft_strlen(s) + 1) * sizeof(*rv));
	if (rv == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		rv[i] = f(i, s[i]);
		i++;
	}
	rv[i] = '\0';
	return (rv);
}
