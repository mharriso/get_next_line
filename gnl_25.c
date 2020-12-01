
#include "get_next_line.h"

static	int	save_next_line(char *buffer, char **line)
{
	char	*new_line;
	char	*update_line;

	if ((new_line = ft_strchr(buffer, '\n')))
		*new_line = '\0';
	if (!(update_line = ft_strjoin(*line, buffer)))
		return (-1);
	free(*line);
	*line = update_line;
	return (new_line) ? 1 : 0;
}

int	get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	int			res;

	if (fd < 0 || BUFFER_SIZE < 1 || !line || !(*line = (char *)malloc(1)))
		return (-1);
	**line = '\0';
	while ((res = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[res] = '\0';
		res = save_next_line(buffer, line);
		if (res != 0)
			break ;
	}
	if (res == -1)
		free(*line);
	return (res);
}
