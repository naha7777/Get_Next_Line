/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacharp <anacharp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:16:24 by anacharp          #+#    #+#             */
/*   Updated: 2025/12/05 10:02:15 by anacharp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_read(int fd, char *buffer)
{
	char	*newbuffer;
	ssize_t	bytes_read;
	char	*tempbuffer;

	newbuffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (newbuffer == NULL)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, newbuffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(newbuffer);
			return (free(buffer), NULL);
		}
		newbuffer[bytes_read] = '\0';
		tempbuffer = buffer;
		buffer = ft_strjoin(tempbuffer, newbuffer);
		free(tempbuffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (free(newbuffer), buffer);
}

static char	*ft_fill(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	line = ft_substr(buffer, 0, (i + 1));
	if (line == NULL)
		return (NULL);
	return (line);
}

static char	*ft_clear(char *buffer)
{
	size_t	len;
	int		i;
	char	*newbuffer;

	i = 0;
	len = ft_strlen(buffer);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	newbuffer = ft_substr(buffer, (i + 1), (len - i));
	if (newbuffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	free(buffer);
	return (newbuffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	if (buffer[fd] == NULL)
		buffer[fd] = ft_strdup("");
	if (buffer[fd] == NULL)
		return (NULL);
	if (!ft_strchr(buffer[fd], '\n'))
		buffer[fd] = ft_read(fd, buffer[fd]);
	if (buffer[fd] == NULL)
		return (NULL);
	if (*buffer[fd] == '\0')
	{
		free(buffer[fd]);
		return (buffer[fd] = NULL, NULL);
	}
	line = ft_fill(buffer[fd]);
	buffer[fd] = ft_clear(buffer[fd]);
	return (line);
}
