/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharriso <mharriso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 03:02:25 by mharriso          #+#    #+#             */
/*   Updated: 2020/11/29 03:58:30 by mharriso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

#include <stdio.h> 				//delete
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define MAGENTA "\033[35;1m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define DOLLAR GREEN"$" RESET 	//delete


int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dest, const void *source, size_t count);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *str);

#endif
