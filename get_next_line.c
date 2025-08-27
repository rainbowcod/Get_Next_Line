/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 00:50:37 by olmatske          #+#    #+#             */
/*   Updated: 2025/08/27 12:36:05 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// shit got memory leaks :(

#include "get_next_line.h"

static char	*copy_buffer(char *buffer, int amount, char *stash, char **leftovers);

char	*get_next_line(int fd)
{
	char buffer[BUFFER_SIZE + 1];
	static char	*leftovers;
	char	*stash;
	int		amount;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (leftovers)
		stash = ft_strdup(leftovers);
	else
	{
		stash = malloc(1);
		if (!stash)
			return (NULL);
	}
	while (ft_strchr(buffer, '\n') == -1)
	{
		amount = read(fd, buffer, BUFFER_SIZE);
		if (amount == -1)
			return (NULL);
		if (amount == 0)
			return (leftovers);
		buffer[amount] = '\0';
		stash = copy_buffer(buffer, amount, stash, &leftovers);
	}
	if (stash[0] == '\0')
	{
		//free(stash);
		return (NULL);
	}
	return (stash);
}

static char	*copy_buffer(char *buffer, int amount, char *stash, char **leftovers)
{
	int		start;
	char	*tmp;

	start = 0;
	if (ft_strchr(buffer, '\n') > -1)
	{
		start = ft_strchr(buffer, '\n');
		if (*leftovers)
		{
			//free(stash);
			stash = ft_strjoin(*leftovers, ft_substr(buffer, 0, start));
			//free(leftovers);
		}
		stash = ft_strjoin(stash, ft_substr(buffer, 0, start));
		*leftovers = ft_substr(buffer, start + 1, amount);
	}
	else
	{
		tmp = ft_strjoin(stash, buffer);
		//free(stash);
		stash = tmp;
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
	int i = 0;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (printf("error"));
	while ((line = get_next_line(fd)) != NULL || i < 30)
	{
		printf("%s", line);
		i++;
		//free(line);
	}
	close(fd);
	return (0);
}