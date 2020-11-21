#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int fd = open("one_line.txt", O_RDONLY);
	char *line;
	int i;
	while((i = get_next_line(fd, &line)))
	{
		printf("i = %d %s$\n", i, line);
		free(line);
	}
	printf("i = %d %s\n", i, line);
		free(line);
	return (0);
}
