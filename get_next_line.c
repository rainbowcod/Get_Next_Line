/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 00:50:37 by olmatske          #+#    #+#             */
/*   Updated: 2025/08/28 21:37:55 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// fix new line aftr second 
// 

#include "get_next_line.h"

static char	*copy_buffer(char *buffer, int amount, char *stash, char **leftovers);

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*leftovers;
	char		*stash;
	int			amount;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!leftovers)
		free(leftovers);
	stash = NULL;
	if (leftovers)
	{
		stash = ft_strdup(leftovers);
		// if (!stash)
		// 	return (NULL);
		// free(leftovers);
		leftovers = NULL;
		if (!stash || (ft_strchr(stash, '\n') != -1))
			return (stash);
	}
	if (!stash)
	{
		stash = malloc(1);
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	while ((amount = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[amount] = '\0';
		stash = copy_buffer(buffer, amount, stash, &leftovers);
		if (!stash)
			return (NULL);
		if (ft_strchr(buffer, '\n') != -1)
			return (stash);
	}
	if (amount < 0)
	{
		free(stash);
		return (NULL);
	}
	if (stash[0])
		return (stash);
	free(stash);
	return (NULL);
}

static char	*copy_buffer(char *buffer, int amount, char *stash, char **leftovers)
{
	int		start;
	char	*tmp;
	char	*substr;

	if (ft_strchr(buffer, '\n') > -1)
	{
		start = ft_strchr(buffer, '\n');
		substr = ft_substr(buffer, 0, start + 1);
		// if (!substr)
		// {
		// 	free (buffer);
		// 	return (NULL);
		// }
		tmp = ft_strjoin(stash, substr);
		free(substr);
		free(stash);
		*leftovers = ft_substr(buffer, start + 1, amount - (start + 1));
		return (tmp);
	}
	tmp = ft_strjoin(stash, buffer);
	free(stash);
	return (tmp);
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

#include <stdio.h>

int	main (void)
{
	int	fd;
	char *line;

	fd = open("tst", O_RDONLY);
	if (fd < 0)
		return (1);

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line: >%s<\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
