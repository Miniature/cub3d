/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:04:02 by wdavey            #+#    #+#             */
/*   Updated: 2023/07/12 16:43:00 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

int	ft_isdigit(int c);

static bool	ft_isspace(char c)
{
	return (
		c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r'
		|| c == ' '
	);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if ('-' == *str)
	{
		sign = -1;
		str++;
	}
	else if ('+' == *str)
		str++;
	result = 0;
	while (ft_isdigit(*str))
	{
		result *= 10;
		result += (*str - '0') * sign;
		str++;
	}
	return (result);
}
