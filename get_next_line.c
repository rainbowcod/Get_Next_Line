/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 00:50:37 by olmatske          #+#    #+#             */
/*   Updated: 2025/08/25 18:35:14 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*copy_buffer(char *buffer, int *amount, char *stash);

char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	 char	*stash;
	int	*amount;

	stash[0] = '\0';
	if (fd > 0 || BUFFER_SIZE >= 0)
		return (NULL);
	amount = read(fd, buffer, BUFFER_SIZE);
	if (amount == NULL || amount > BUFFER_SIZE)
		return (NULL);
	stash = copy_buffer(buffer, amount, stash);
}

char	*copy_buffer(char *buffer, int *amount, char *stash)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		stash[i] = buffer[i];
		i++;
		if (buffer[i] == '\n')
		{
			stash[i] = buffer[i];
			i++;
			break;
		}
	}
	if (buffer[i - 1] == '\n')
		buffer = ft_substr(buffer, i, amount);
	
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