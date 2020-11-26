#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define DOLLAR GREEN"$" RESET

int main()
{
	int fd = open("alphabet.txt", O_RDONLY);
	char *line;
	int i;
	while((i = get_next_line(fd, &line)))
	{
		printf("i = %d %s%s\n", i, line, DOLLAR);
		free(line);
	}
	printf("i = %d %s\n", i, line);
		free(line);
	//for(;;)
	return (0);
}
