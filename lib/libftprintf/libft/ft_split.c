/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:32:11 by wdavey            #+#    #+#             */
/*   Updated: 2023/07/12 18:53:54 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

static size_t	count_words(const char *str, char c)
{
	size_t	num;
	char	*word_end;

	num = 0;
	while ('\0' != *str)
	{
		if (*str == c)
		{
			str++;
			continue ;
		}
		num++;
		word_end = ft_strchr(str, c);
		if (NULL == word_end)
			break ;
		str = word_end;
	}
	return (num);
}

static char	**make_words_array(const char *str, char c)
{
	size_t	count;
	char	**words;

	if (NULL == str)
		return (NULL);
	count = count_words(str, c);
	words = malloc((count +1) * sizeof(*words));
	if (NULL == words)
		return (NULL);
	words[count] = NULL;
	return (words);
}

static char	**handle_misalloc(char **words, size_t word_count)
{
	size_t	i;

	i = 0;
	while (i <= word_count)
	{
		if (NULL != words[i])
			free(words[i]);
		i++;
	}
	free(words);
	return (NULL);
}

char	**ft_split(const char *str, char c)
{
	size_t		word_count;
	char		**words;

	words = make_words_array(str, c);
	if (NULL == words)
		return (NULL);
	word_count = 0;
	while (NULL != str && '\0' != *str)
	{
		if (str < ft_strchr(str, c) || (*str != c && ft_strlen(str) > 0))
		{
			if (str < ft_strchr(str, c))
				words[word_count] = ft_substr(str, 0, ft_strchr(str, c) - str);
			else
				words[word_count] = ft_strdup(str);
			if (NULL == words[word_count])
				return (handle_misalloc(words, word_count));
			word_count++;
			str = ft_strchr(str, c);
		}
		else
			str++;
	}
	return (words);
}
