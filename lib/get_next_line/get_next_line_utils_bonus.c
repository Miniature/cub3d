/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdavey <wdavey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:32:37 by wdavey            #+#    #+#             */
/*   Updated: 2023/07/21 12:24:20 by wdavey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && *(s + len))
	{
		len++;
	}
	return (len);
}

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i < dstsize && dst[i] != '\0')
		i++;
	if (i == dstsize)
		return (i + ft_strlen(src));
	while (i < dstsize - 1 && *src != '\0')
	{
		dst[i] = *src;
		src++;
		i++;
	}
	dst[i] = '\0';
	while (*src != '\0')
	{
		src++;
		i++;
	}
	return (i);
}

char	*ft_substr(const char *s, size_t start, size_t len)
{
	char	*substr;

	if (NULL == s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		substr = malloc(1);
		if (NULL == substr)
			return (NULL);
		*substr = '\0';
		return (substr);
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	substr = malloc((len + 1) * sizeof(*substr));
	if (NULL == substr)
		return (NULL);
	substr[len] = 0;
	while (len--)
	{
		substr[len] = s[start + len];
	}
	return (substr);
}

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

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (len == 0 || *needle == '\0')
		return ((char *)haystack);
	while ('\0' != *haystack && len > 0)
	{
		i = 0;
		while (i < len && haystack[i] == needle[i])
		{
			i++;
			if (needle[i] == '\0')
				return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (NULL);
}
