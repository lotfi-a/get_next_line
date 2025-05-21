/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laanikid <laanikid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:29:12 by laanikid          #+#    #+#             */
/*   Updated: 2025/05/21 23:36:48 by laanikid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*update_stash(char *stash)
{
	char	*new;
	int		i;

	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
		{
			new = ft_substr(stash, i + 1, ft_strlen(stash) - (i + 1));
			free(stash);
			return (new);
		}
		i++;
	}
	free(stash);
	return (NULL);
}

char	*extract_line(char *stash)
{
	int	len;

	if (!stash || stash[0] == '\0')
		return (NULL);
	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	return (ft_substr(stash, 0, len));
}

static char	*append_line(int fd, char *stash, char *buffer, ssize_t *bytes)
{
	char	*tmp;

	*bytes = read(fd, buffer, BUFFER_SIZE);
	if (*bytes <= 0)
		return (stash);
	buffer[*bytes] = '\0';
	if (!stash)
		stash = ft_strdup("");
	if (!stash)
		return (NULL);
	tmp = ft_strjoin(stash, buffer);
	free(stash);
	return (tmp);
}

char	*read_to_stash(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while ((!stash || !ft_strchr(stash, '\n')) && bytes > 0)
	{
		stash = append_line(fd, stash, buffer, &bytes);
		if (!stash)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	if (bytes == -1 || !stash || !stash[0])
		return (free(stash), NULL);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_to_stash(fd, stash);
	if (!stash || stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = extract_line(stash);
	stash = update_stash(stash);
	return (line);
}
