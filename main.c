#include "get_next_line.h"
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("teste1.txt", O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		printf("Vindo nulo");
	while (line)
	{
		printf("%s", line);
		//free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

//int	main(void)
//{
//	int		fd;
//	char	*line;

//	fd = open("teste1.txt", O_RDONLY);
//	line = get_next_line(fd);
//	printf("%s", line);
//	//while (line)
//	//{
//	//	line = get_next_line(fd);
//	//	printf("%s", line);
//	//}
//	close (fd);
//	return (0);
//}

// int	main(void)
//{
//	int		fd;
//	char	*retorno;

//	fd = open("teste1.txt", O_RDONLY);
//	retorno = get_next_line(fd);
//	while (retorno)
//	{
//		printf("%s", retorno);
//		retorno = get_next_line(fd);
//	}
//	close (fd);
//	return (0);
//}
