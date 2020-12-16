static	char	*ft_joinchr(char const *s1, char c, size_t len)
{
	char		*s;
	size_t		i;

	if (!(s = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < len)
		s[i++] = (*s1) ? *s1++ : c;
	s[i] = '\0';
	return (s);
}
int		get_next_line(int fd, char **line)
{
	char		buffer;
	int			res;
	char		*tmp;
	size_t		len;

	if (fd < 0 || BUFFER_SIZE != 1 || !line || !(*line = (char *)malloc(1)))
		return (-1);
	**line = '\0';
	len = 0;
	while ((res = read(fd, &buffer, BUFFER_SIZE)) > 0 && buffer != '\n')
	{
		len++;
		if (!(tmp = ft_joinchr(*line, buffer, len)))
			res = -1;
		res = 0;
		free(*line);
		*line = tmp;
		if (res != 0)
			break ;
	}
	if (res == -1)
		free(*line);
	return (res);
}
