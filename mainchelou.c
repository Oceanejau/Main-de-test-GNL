#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int ret;
	char *line;
	int fd;
	(void)ac;
	fd = open(av[1], O_RDONLY);
	while((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%d | %s\n", ret, line);
		free(line);
	}
	printf("%d | %s\n", ret, line);
	free(line);
	close(fd);
	fd = open(av[2], O_RDONLY);
	while((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%d | %s\n", ret, line);
		free(line);
	}
	printf("%d | %s\n", ret, line);
	free(line);
	close(fd);
	//while (1);
	return (0);
}
