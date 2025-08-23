/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 14:43:47 by mkitano           #+#    #+#             */
/*   Updated: 2025/08/23 18:01:39 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
	static char	*remaining;
	char		*line;
	char		*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if ((fd < 0) | (BUFFER_SIZE <= 0))
	{
		free (buffer);
		remaining = NULL;
		return (NULL);
	}
	line = read_line(fd, remaining, buffer);
}

char	*read_line(int fd, char *remaining, char *buffer)
{
	
}
