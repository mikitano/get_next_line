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
	while (bytes_read > 0) && (ft_strchr(remaining, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		else if (bytes_read == 0)
			return (remaining);
		buffer[bytes_read] = '\0';
		else
		{
			buffer = ft_substr()
		}
	}
}
