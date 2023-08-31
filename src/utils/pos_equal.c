/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_equal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:00:10 by wdavey            #+#    #+#             */
/*   Updated: 2023/08/30 16:00:36 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	pos_equal(t_pos a, t_pos b)
{
	return (a.x == b.x && a.y == b.y);
}
