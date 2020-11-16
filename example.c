#include <fcntl.h>
#include <unistd.h>

int		display_file(char const *name)
{
	int		f;
	char	buf[1];

	f = open(name, O_RDONLY);
	while (read(f, buf, sizeof(buf)))
	{
		write(1, buf, sizeof(buf));
	}
	write(1, "\n\n", 2);
    close(f);
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
