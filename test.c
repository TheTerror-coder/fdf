#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include "include/libft/libft.h"
#include "include/get_next_line/get_next_line.h"
#include "mlx.h"



int	main(int argc, char *argv[])
{
	int		i;
	int		fd;
	char	*line;

	fd = argc;
	i = 0;
	line = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	printf("%d\n", i);
	fd = close(fd);
	if (fd < 0)
		return (0);
	return (0);
}