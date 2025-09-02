/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 21:34:01 by olmatske          #+#    #+#             */
/*   Updated: 2025/09/02 13:53:59 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"









// problems: check for values in buffer

// char	*get_line(int fd, char *tmp, char *buffer, int amount);
// char	*read_file(int fd, char *tmp, char *buffer, int amount);

// char	*get_next_line(int fd)
// {
// 	static char	buffer[BUFFER_SIZE + 1];
// 	char		*tmp;
// 	char		*res;
// 	int			amount;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
	
// 	return (res);
// }
// char	*read_file(int fd, char *tmp, char *buffer, int amount)
// {
// 	amount = 1;

// 	if new line in buffer
// 		return get_line
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
// 		res = get_line(fd, tmp, buffer, amount); // check if result is empty, if not -> free
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
// 			// set whole buffer array to \0
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

void	*ft_bezero(char *str, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		str[i++] = '\0';
	return (str);
}
