/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 14:43:47 by mkitano           #+#    #+#             */
/*   Updated: 2025/08/26 20:17:02 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *remaining, char *buffer);
char	*printable_line(char *buffer);
char	*save_content(char *buffer);

char	*get_next_line(int fd)
{
	static char	*remaining;
	char		*line;
	char		*buffer;

	if ((fd < 0) | (BUFFER_SIZE <= 0))
	{
		free(buffer);
		remaining = NULL;
		return (NULL);
	}
	buffer = read_line(fd, remaining, buffer);
	line = printable_line(buffer);
	if (!line)
	{
		free(buffer);
		return (NULL);
	}
	remaining = save_content(buffer);
	return (line);
}

char	*read_line(int fd, char *remaining, char *buffer)
{
	int		bytes_read;
	char	*temp;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && ft_strchr(remaining, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		else if (bytes_read == 0)
			return (remaining);
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(remaining, buffer);
		// if (!temp)
		// {
		// 	free(temp);
		// 	return (NULL);
		// }
		free(remaining);
		remaining = temp;
	}
	return (temp);
}

char	*printable_line(char *buffer)
{
	int		i;
	char	*printable;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] != '\n')
	{
		i++;
		if (buffer[i] == '\0')
		{
			printable = ft_strdup(buffer);
		}
	}
	printable = ft_substr(buffer, 0, i);
	*printable++ = '\n';
	if (!printable)
	{
		free (printable);
		return (NULL);
	}
	return (printable);
}

char	*save_content(char *buffer)
{
	int		i;
	int		j;
	char	*save_remaining;

	i = 0;
	j = 0;
	if (buffer[i] == '\0')
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
		i++;
	save_remaining = malloc((ft_strlen(buffer) - i) + 1 * sizeof(char));
	if (!save_remaining)
		return (NULL);
	while (buffer[i] != '\0')
		save_remaining[j++] = buffer[i++];
	save_remaining[j] = '\0';
	return (save_remaining);
}
//fução para dar free?