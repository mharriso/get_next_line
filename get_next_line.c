/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharriso <mharriso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 00:31:51 by mharriso          #+#    #+#             */
/*   Updated: 2020/11/27 05:15:26 by mharriso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int save_cache_line(char *new_line, char *cache)
{
	char *update_cache;

	if(!new_line)
		return (0);
	update_cache = NULL;
	if(*(new_line + 1) != '\0')
		if(!(update_cache = ft_strjoin(new_line + 1, cache)))
			return (-1);
	free(cache);
	cache = update_cache;
	return (1);
}

int	save_next_line(char *buffer, char **line, char *cache)
{
	char	*new_line;
	char	*update_line;

	if(buffer == NULL)
		return (0);
	if((new_line = ft_strchr(buffer, '\n')))
		*new_line = '\0';
	if(!(update_line = ft_strjoin(*line, buffer)))
		return (-1);
	free(*line);
	*line = update_line;
	return (new_line) ? 1 : 0;
}

int	get_next_line(int fd, char **line)
{
	static char	*cache = NULL;
	char		buffer[BUFFER_SIZE + 1];
	int			res;

	if(!(*line = ft_strjoin("", "")))
		return (-1);
	while((res = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[res] = '\0';
		res = save_next_line(buffer, line, cache);
		if(res != 0)
			break ;
	}
	if(res == -1)
	{
		free(cache);
		free(*line);
	}
	return (res);
}

