#include <sys/types.h>
#include "get_next_line/get_next_line.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		i;
	int		j;

	(void)ac;
	//(void)av;
	i = 1;
	fd = open(av[1], O_RDONLY);
	//fd = 0;
	while((j = get_next_line(fd, &line)) > 0)
	{
		printf("%d Ligne %d : %s\n", j, i, line);
		i++;
		free(line);
		//line = NULL;
	}
	printf("%d Ligne %d : %s\n", j, i, line);
	free(line);
	close(fd);
	/*
	i = 1;
	fd = open(av[2], O_RDONLY);
	while((j = get_next_line(fd, &line)) > 0)
	{
		printf("%d Ligne %d : %s\n", j, i, line);
		i++;
		free(line);
		//line = NULL;
	}
	printf("%d Ligne %d : %s\n", j, i, line);
	free(line);
	close(fd);
	*/
	return (0);
}
