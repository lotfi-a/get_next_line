/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laanikid <laanikid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:19:15 by laanikid          #+#    #+#             */
/*   Updated: 2025/05/21 23:03:13 by laanikid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>

size_t	ft_strlen(const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*dup;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(src);
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	while (*src)
		dup[i++] = *src++;
	dup[i] = '\0';
	return (dup);
}

char	*ft_substr(const char *src, unsigned int start, size_t size)
{
	char	*sub;
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	if (start >= len)
		return (ft_strdup(""));
	if (size > len - start)
		size = len - start;
	sub = malloc(sizeof(char) * (size + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < size)
	{
		sub[i] = src[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	char	*dst;
	size_t	j;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	i = 0;
	j = 0;
	dst = malloc(len_s1 + len_s2 + 1);
	if (!dst)
		return (NULL);
	while (i < len_s1)
	{
		dst[i] = s1[i];
		i++;
	}
	while (j < len_s2)
	{
		dst[i + j] = s2[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst);
}

char	*ft_strchr(const char *str, int ch)
{
	while (*str)
	{
		if ((unsigned char)*str == (unsigned char)ch)
			return ((char *)str);
		str++;
	}
	if ((unsigned char)*str == (unsigned char)ch)
		return ((char *)str);
	return (NULL);
}
