/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:10:53 by wdavey            #+#    #+#             */
/*   Updated: 2023/08/16 21:37:24 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_max(long a, long b)
{
	if (a > b)
		return (a);
	return (b);
}

unsigned long	ft_umax(unsigned long a, unsigned long b)
{
	if (a > b)
		return (a);
	return (b);
}
