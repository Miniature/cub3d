/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:55:13 by wdavey            #+#    #+#             */
/*   Updated: 2023/07/11 16:36:46 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n > 0)
	{
		n--;
		*(unsigned char *)(dst + n) = *(unsigned char *)(src + n);
	}
	return (dst);
}
