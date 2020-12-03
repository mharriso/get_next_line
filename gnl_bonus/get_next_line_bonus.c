/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharriso <mharriso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 00:31:51 by mharriso          #+#    #+#             */
/*   Updated: 2020/12/03 22:34:14 by mharriso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static	int		save_next_line(char *buffer, char **line, char **cache)
{
	char	*new_line;
	char	*tmp;

	if (!buffer)
		return (0);
	if ((new_line = ft_strchr(buffer, '\n')))
		*new_line = '\0';
	if (!(tmp = ft_strjoin(*line, buffer)))
		return (-1);
	free(*line);
	*line = tmp;
	tmp = NULL;
	if (new_line && *(new_line + 1) != '\0')
		if (!(tmp = ft_strjoin(new_line + 1, "")))
			return (-1);
	free(*cache);
	*cache = tmp;
	return ((new_line) ? 1 : 0);
}

static	void	free_cache(char **cache)
{
	int	i;

	i = 0;
	while (i < 1024)
	{
		if (cache[i] != NULL)
		{
			free(cache[i]);
			cache[i] = NULL;
		}
		i++;
	}
}

int				get_next_line(int fd, char **line)
{
	static char	*cache[1024] = {NULL};
	char		buffer[BUFFER_SIZE + 1];
	int			res;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE < 1 || !line
	|| !(*line = (char *)malloc(1)))
		return (-1);
	**line = '\0';
	if ((res = save_next_line(cache[fd], line, &cache[fd])) == 1)
		return (res);
	while ((res = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[res] = '\0';
		res = save_next_line(buffer, line, &cache[fd]);
		if (res != 0)
			break ;
	}
	if (res == -1)
	{
		free(*line);
		free_cache(cache);
	}
	return (res);
}
