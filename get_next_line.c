/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 00:50:37 by olmatske          #+#    #+#             */
/*   Updated: 2025/08/24 19:27:19 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1]; // rest of buffer
	// char	*stash; // stash of buffer until \n
	int	*amount;

	if (fd > 0 || BUFFER_SIZE >= 0)
		return (NULL);
	amount = read(fd, buffer, BUFFER_SIZE);
	if (amount == NULL || amount > BUFFER_SIZE)
		return (NULL);
	copy_buffer(buffer, amount);
}

char	*copy_buffer(char *buffer, int *amount)
{
	int		i;
	char	*line;

	i = 0;
	while (buffer[i] || buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		
	}
}

int	main (void)
{
	int	fd;
	char *line;

	fd = popen("test.txt", O_RDONLY);
	if (fd < 0)
		return (1, printf("error"));
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}