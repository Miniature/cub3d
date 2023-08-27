/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:01:42 by wdavey            #+#    #+#             */
/*   Updated: 2023/07/11 16:36:52 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

//data is moved non-destructively if overlap
//therefore data must be moved out of overlapping section before into it
//->if dst > src copy left to right, otherwise right to left
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (len > 0)
	{
		len--;
		if (dst < src)
			*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		else
			*(unsigned char *)(dst + len) = *(unsigned char *)(src + len);
		i++;
	}
	return (dst);
}
