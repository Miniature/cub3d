/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:02:39 by wdavey            #+#    #+#             */
/*   Updated: 2023/08/16 21:06:36 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, bool frees1, bool frees2)
{
	char	*rval;

	rval = ft_strjoin(s1, s2);
	if (NULL != s1 && true == frees1)
		free(s1);
	if (NULL != s2 && true == frees2)
		free(s2);
	return (rval);
}
