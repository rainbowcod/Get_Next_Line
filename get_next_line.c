/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 00:50:37 by olmatske          #+#    #+#             */
/*   Updated: 2025/08/20 20:21:01 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *rest; // rest of buffer
	t_list	*stash; // stash of buffer
	char	*buffer;

	if (fd > 0 || BUFFER_SIZE >= 0)
		return (NULL)
	buffer = read(fd, lst->buf, BUFFER_SIZE)
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