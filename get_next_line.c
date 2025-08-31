/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 00:50:37 by olmatske          #+#    #+#             */
/*   Updated: 2025/08/31 18:17:04 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// fix new line aftr second 
// do static buffer so that you have less leaks

#include "get_next_line.h"

static int	buffer_read(int fd, char *stash, char *buffer, int amount);
static char	*buffer_copy(char *buffer, char *stash, int amount);

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char	*stash;
	int		amount;

	
}

static int	buffer_read(int fd, char *stash, char *buffer, int amount)
{
	char	*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	amount = read(fd, buffer, BUFFER_SIZE);
	while (amount > 0)
	{
		buffer[BUFFER_SIZE + 1] = '\0';
		tmp = 
	}
	while ()
}

static char	*buffer_copy(char *buffer, char *stash, int amount)
{
	
}

#include <stdio.h>

int	main (void)
{
	int	fd;
	char *line;

	fd = open("tst", O_RDONLY);
	if (fd < 0)
		return (1);

	line = get_next_line(fd);
	printf("Line: >%s<\n", line);
	free(line);
	line = get_next_line(fd);
	printf("Line: >%s<\n", line);
	free(line);
	close(fd);
	return (0);
}
