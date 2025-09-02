/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 21:34:01 by olmatske          #+#    #+#             */
/*   Updated: 2025/09/02 12:59:12 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// problems: where do I read and put in tmp and clean buffer???

char	*get_line(int fd, char *tmp, char *buffer, int amount);

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*tmp;
	char		*res;
	int			amount;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	amount = 1;
	while (amount > 0)
	{
		amount = read(fd, buffer, BUFFER_SIZE);
		tmp = ft_strdup(buffer);
		if (!tmp)
			return (NULL);
		ft_bezero(buffer, amount); // use BUFFER_SIZE but why?
		res = get_line(fd, tmp, buffer, amount);
		if (!res)
			return (NULL);
	}
}
char	*get_line(int fd, char *tmp, char *buffer, int amount)
{
	char	*res;
	int		nl;

	while (amount > 0)
	{
		if (ft_strchr(tmp, '\n') > -1)
		{
			nl = ft_strchr(tmp, '\n');
			res = ft_substr(tmp, 0, nl + 1);
			ft_strlcpy(buffer, tmp + nl + 1, BUFFER_SIZE);
		}
	}
}

void	*ft_bezero(char *str, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		str[i++] = '\0';
	return (str);
}