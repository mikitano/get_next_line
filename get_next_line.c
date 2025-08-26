/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 14:43:47 by mkitano           #+#    #+#             */
/*   Updated: 2025/08/24 17:33:21 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
	static char	*remaining;
	char		*line;
	char		*buffer;

	//buffer = malloc((remaining + 1) * sizeof(char));
	//if (!buffer)
	//	return (NULL);
	if ((fd < 0) | (BUFFER_SIZE <= 0))
	{
		free(buffer);
		remaining = NULL;
		return (NULL);
	}
	buffer = read_line(fd, remaining, buffer);
	//line = read_line(fd, remaining, buffer);
	line = printable_line();
	if (!line)
	{
		free(buffer);
		return (NULL);
	}
	remaining = save_content();
	return (line);
}

char	*read_line(int fd, char *remaining, char *buffer)
{
	int		bytes_read;
	char	*temp;

	if (!buffer)
		buffer = ft_strdup(remaining);
	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	bytes_read = 1;
	while (bytes_read > 0 && ft_strchr(remaining, '\n')
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
}

char	*printable_line(int fd, char *remaining, char *buffer)
{
	int		i;
	char	*printable;

	i = 0;
	if(!remaining)
		return (NULL);
	while(remaining[i] != '\n')
	{
		i++;
		if (remaining[i] == '\0')
		{
			printable = ft_strdup(remaining);
		}
	}
	printable = ft_substr(remaining, 0, i));
	printable++ = '\n';
	if(!printable)
	{
		free (printable);
		return (NULL);
	}
	return (printable);
}

char	*save_content(char *remaining, char *buffer)
{
	int		i;
	char	*save_remaining;

	i = 0;
	while(buffer[i] != '\n')
	{
		i++;
		if(buffer[i] == '\0')
		{
			free(free (save_remaining);
			free (buffer);
			return (NULL);)
		}
	}
	save_remaining = ft_substr(remaining, i, (ft_strlen(buffer) - i));
	buffer = save_remaining;
	if(!save_remaining)
	{
		free (save_remaining);
		free (buffer);
		return (NULL);
	}
	return (save_remaining);
}
