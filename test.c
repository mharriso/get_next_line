#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int fd = open("one_line.txt", O_RDONLY);
	char line[200];

	int count;

	count = read(fd, line, 3);
	printf("%d %s\n", count, line);

	count = read(fd, line, 3);
	printf("%d %s\n", count, line);

	count = read(fd, line, 3);
	printf("%d %s\n", count, line);


	return (0);
}
