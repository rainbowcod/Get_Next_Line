/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 00:50:37 by olmatske          #+#    #+#             */
/*   Updated: 2025/08/23 13:00:17 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1]; // rest of buffer
	char	*stash; // stash of buffer until \n
	int	*readline;

	if (fd > 0 || BUFFER_SIZE >= 0)
		return (NULL);
	readline = read(fd, stash, BUFFER_SIZE);
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