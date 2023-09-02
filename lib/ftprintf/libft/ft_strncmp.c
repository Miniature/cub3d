/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:44:19 by wdavey            #+#    #+#             */
/*   Updated: 2023/07/12 13:21:44 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (--n && *s1 == *s2 && '\0' != *s1)
	{
		s1++;
		s2++;
	}
	if ((unsigned)*s1 > (unsigned)*s2)
		return (1);
	if ((unsigned)*s1 < (unsigned)*s2)
		return (-1);
	return (0);
}
