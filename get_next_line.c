/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 00:50:37 by olmatske          #+#    #+#             */
/*   Updated: 2025/08/26 22:32:30 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// shit got memory leaks :(

#include "get_next_line.h"

static char	*copy_buffer(char *buffer, int amount, char *stash);

char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	char	*stash;
	int		amount;

	stash[0] = '\0';
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (ft_strchr(buffer, '\n') == -1)
	{
		amount = read(fd, buffer, BUFFER_SIZE);
		if (amount == -1)
			return (NULL);
		stash = copy_buffer(buffer, amount, stash);
	}
	return (stash);
}

static char	*copy_buffer(char *buffer, int amount, char *stash)
{
	int	start;

	start = 0;
	if (ft_strchr(buffer, '\n') != -1)
	{
		start = ft_strchr(buffer, '\n');
		stash = malloc(sizeof(char) * start);
		stash = ft_strjoin(stash, ft_substr(buffer, 0, start));
	}
	else
	{
		stash = malloc(sizeof(amount));
		stash = ft_strjoin(stash, buffer);
	}
	return (stash);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] && i < dstsize - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

// static char	*copy_buffer(char *buffer, int *amount, char *stash)
// {
// 	int	i;

// 	i = 0;
// 	while (buffer[i])
// 	{
// 		if (buffer[i] == '\n')
// 		{
// 			stash[i] = buffer[i];
// 			i++;
// 			break;
// 		}
// 		stash[i] = buffer[i];
// 		i++;
// 	}
// 	if (buffer[i - 1] == '\n')
// 		buffer = ft_substr(buffer, i, amount - i);
	
// }

int	main (void)
{
	int	fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (printf("error"));
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}