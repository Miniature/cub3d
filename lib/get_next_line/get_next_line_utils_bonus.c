/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:32:37 by wdavey            #+#    #+#             */
/*   Updated: 2023/08/28 12:57:30 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include "libft.h"

//always frees s1 and s2
char	*ft_strjoin_f(char *s1, char *s2)
{
	char	*joined;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	joined = malloc (len * sizeof(*joined));
	if (NULL == joined)
	{
		if (NULL != s1)
			free(s1);
		if (NULL != s2)
			free(s2);
		return (NULL);
	}
	joined[0] = '\0';
	if (NULL != s1)
	{
		ft_strlcat(joined, s1, len);
		free(s1);
	}
	if (NULL != s2)
	{
		ft_strlcat(joined, s2, len);
		free(s2);
	}
	return (joined);
}
