#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

int	main(void)
{
	int		fd;
	char	*retorno;

	fd = open("teste1.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	close (fd);
	return (0);
}
