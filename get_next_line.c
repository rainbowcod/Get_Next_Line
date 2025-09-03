/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 21:34:01 by olmatske          #+#    #+#             */
/*   Updated: 2025/09/03 13:58:45 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_loop(int fd, char *buffer, char *tmp, int amount);
char	*ft_check_buffer(char *buffer, char *tmp);

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*tmp;
	char		*res;
	int			nl;
	int			amount;

	tmp = NULL;
	amount = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	tmp = ft_check_buffer(buffer, tmp);
	tmp = ft_loop(fd, buffer, tmp, amount);
	if (!tmp || ft_strlen(tmp) == 0)
		return (free(tmp), NULL);
	nl = ft_strchr(tmp, '\n');
	if (nl == -1)
		return (tmp);
	res = ft_substr(tmp, 0, nl + 1);
	if (!res)
		return (free(tmp), NULL);
	if (ft_strlen(tmp + nl + 1) > 0)
		ft_strlcpy(buffer, tmp + nl + 1, BUFFER_SIZE + 1);
	free(tmp);
	return (res);
}

char	*ft_check_buffer(char *buffer, char *tmp)
{
	if (ft_strlen(buffer) > 0)
	{
		tmp = ft_strjoin(tmp, buffer);
		if (!tmp)
			return (ft_bezero(buffer, BUFFER_SIZE + 1), NULL);
		ft_bezero(buffer, BUFFER_SIZE + 1);
	}
	return (tmp);
}

char	*ft_loop(int fd, char *buffer, char *tmp, int amount)
{
	while (ft_strchr(tmp, '\n') == -1 && amount != 0)
	{
		amount = read(fd, buffer, BUFFER_SIZE);
		if (amount < 0)
			return (free(tmp), ft_bezero(buffer, BUFFER_SIZE + 1), NULL);
		buffer[amount] = '\0';
		tmp = ft_strjoin(tmp, buffer);
		if (!tmp)
			return (ft_bezero(buffer, BUFFER_SIZE + 1), NULL);
		ft_bezero(buffer, BUFFER_SIZE + 1);
	}
	return (tmp);
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

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("tst", O_RDONLY);
// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	return (0);
// }
