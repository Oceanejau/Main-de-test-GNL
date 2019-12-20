#include "../get_next_line/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int		main(int ac, char **av)
{
	int  *fd;
	int i;
	int  ret;
	int	reste;
	char *line;

	i = 0;
	if (!(fd = (int *)malloc(sizeof(int) * (ac + 1))))
		return (0);
	fd[ac + 1] = -2;
	while (ac > i++)
		fd[i] = open(av[i], O_RDONLY);
	reste = 1;
	while (reste > 0)
	{
		i = 0;
		reste = 0;
		while (fd[++i] != -2 && i <= ac)
		{
			if (fd[i] != -1)
				ret = get_next_line(fd[i], &line);
			if (fd[i] > 0 && ret == 1)
			{
				printf("RETURN =========== %d: fd = %d, |%s|\n", ret, i, line);
				reste++;
			}
			if (fd[i] > 0 && ret == 0)
			{
				printf("RETURN =========== %d: fd = %d, |%s|\n", ret, i, line);
				free(line);
				close(fd[i]);
				fd[i] = -1;
			}
		}
	}
	free(line);
	close(fd[i]);
	return (0);
}
