/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 22:22:05 by wdavey            #+#    #+#             */
/*   Updated: 2023/08/15 22:22:27 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_min(long a, long b)
{
	if (a < b)
		return (a);
	return (b);
}

unsigned long	ft_umin(unsigned long a, unsigned long b)
{
	if (a < b)
		return (a);
	return (b);
}
