/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 21:34:01 by olmatske          #+#    #+#             */
/*   Updated: 2025/09/03 12:27:42 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// problems: check for values in buffer

// char	*get_line(int fd, char *tmp, char *buffer, int amount);
// char	*read_file(int fd, char *tmp, char *buffer);

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*tmp;
	char		*res;
	int			nl;
	int			amount;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	tmp = NULL;
	amount = 1;
	if (ft_strlen(buffer) > 0)
	{
		tmp = ft_strjoin(tmp, buffer);
		if (!tmp)
		{
			ft_bezero(buffer, BUFFER_SIZE + 1);
			return (NULL);
		}
		ft_bezero(buffer, BUFFER_SIZE + 1);
	}
	while (ft_strchr(tmp, '\n') == -1 && amount != 0)
	{
		amount = read(fd, buffer, BUFFER_SIZE);
		if (amount < 0)
		{
			free(tmp);
			ft_bezero(buffer, BUFFER_SIZE + 1);
			return (NULL);
		}
		buffer[amount] = '\0';
		tmp = ft_strjoin(tmp, buffer);
		if (!tmp)
		{
			ft_bezero(buffer, BUFFER_SIZE + 1);
			return (NULL);
		}
		ft_bezero(buffer, BUFFER_SIZE + 1);
	}
	if (!tmp || ft_strlen(tmp) == 0)
		return (free(tmp), NULL);
	nl = ft_strchr(tmp, '\n');
	if (nl == -1)
		return (tmp);
	res = ft_substr(tmp, 0, nl + 1);
	if (!res)
		return (free(tmp),NULL); //tmp indtead of res
	if (ft_strlen(tmp + nl + 1) > 0) // tmp instead of res
		ft_strlcpy(buffer, tmp + nl + 1, BUFFER_SIZE + 1);
	free(tmp);
	return (res);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	if (!src)
		return (0);
	i = 0;
	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	while (src[i] && i < dstsize - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}

void	*ft_bezero(char *str, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		str[i++] = '\0';
	return (str);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("tst", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	return (0);
}

// char	*read_file(int fd, char *tmp, char *buffer)
// {
// 	amount = 1;

// 	// if new line in buffer
// 	// 	return get_line
// 	while (amount > 0)
// 	{
// 		if (res)
// 		{
// 			free (res);
// 			res = NULL;
// 		}
// 		if (buffer not empty)
// 			tmp = ft_strdup(buffer);

// 		amount = read(fd, buffer, BUFFER_SIZE);
// 		buffer[amount] = '\0';
// 		if (!tmp)
// 			return (NULL);
// 		// ft_bezero(buffer, amount); // use BUFFER_SIZE but why?
// 		res = get_line(fd, tmp, buffer, amount); // check if result is empty,
// if not -> free
// 		if (!res)
// 			return (NULL);
// 	}
// }

// char *read_file:
// 	if (new line in buffer)
// 		return strdup(buffer)
// 	else
// 		while()
// read from file
// extratc from readed
// update buffer

// char	*get_line(int fd, char *tmp, char *buffer, int amount)
// {
// 	char	*res;
// 	int		nl;

// 	while (amount > 0 || ft_strchr(tmp, '\n') > -1)
// 	{
// 		if (ft_strchr(tmp, '\n') > -1)
// 		{
// 			nl = ft_strchr(tmp, '\n');
// 			res = ft_substr(tmp, 0, nl + 1);
// 			ft_strlcpy(buffer, tmp + nl + 1, BUFFER_SIZE);
// 			free (tmp);
// 			tmp = NULL;
// 			return (res);
// 		}
// 		else
// 		{
// 			res = ft_strjoin(res, tmp);
// 			ft_bezero(buffer, amount);
// 		}
// 	}
// 	return (res);
// }
