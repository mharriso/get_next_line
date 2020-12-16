
int	get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	int			res;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE != 1 || !line || !(*line = (char *)malloc(1)))
		return (-1);
	**line = '\0';
	while ((res = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[res] = '\0';
		if (*buffer == '\n')
			return (1);
		res = 0;
		if (!(tmp = ft_strjoin(*line, buffer)))
			res = -1;
		free(*line);
		*line = tmp;
		if (res != 0)
			break ;
	}
	if (res == -1)
		free(*line);
	return (res);
}
