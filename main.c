#include <fcntl.h>
#include <string.h>
#include "get_next_line.h"


int	test_gnl(int fd, char *line)
{
	int i;
	printf(MAGENTA"\n********************************** ( fd %d ) *********************************\n\n"RESET, fd);
	while((i = get_next_line(fd, &line)) > 0)
	{
		printf("i = %d %s%s\n", i, line, DOLLAR);
		free(line);
	}
	printf("i = %d %s%s\n", i, line, DOLLAR);
	free(line);
	return 0;
}
int main()
{
	int fd[10];
	char *line;

	memset(fd, 0, 10);

	fd[0] =  open("alphabet.txt", O_RDONLY);
	fd[1] =  open("all_i_ask.txt", O_RDONLY);
	fd[2] =  open("empty.txt", O_RDONLY);
	fd[3] =  open("file0.txt", O_RDONLY);
	fd[4] =  open("fail.txt", O_RDONLY);

	for(int i = 0; i < 5; i++)
		test_gnl(fd[i], line);

	//while(1){}
	return (0);
}
