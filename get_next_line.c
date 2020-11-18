/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharriso <mharriso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 00:31:51 by mharriso          #+#    #+#             */
/*   Updated: 2020/11/18 01:29:35 by mharriso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char *ptr;
	while((ptr = strchr(line, '\n') == NULL))
	{
		read(fd, line, BUFFER_SIZE);
		if()
	}

	return 0;
}
