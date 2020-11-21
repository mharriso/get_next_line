#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int		display_file(char const *name)
{
	int		fd;
	char	buf[1];

	fd = open(name, O_RDONLY);
	while (read(fd, buf, sizeof(buf)))
	{
		write(1, buf, sizeof(buf));
	}
	close(fd);
	return (0);
}

int		main(int argc, char const **argv)
{
	if (argc > 1)
	{
		int s;
		s = 1;
		while(argv[s] != '\0')
		{
			display_file(argv[s]);
			s++;
		}
	}
	return (0);
}
