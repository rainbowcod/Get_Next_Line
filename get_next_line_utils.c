/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:16:33 by olmatske          #+#    #+#             */
/*   Updated: 2025/08/25 18:01:42 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str && *str != (char)c)
		(str)++;
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*res;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (s1)
		ft_strlcpy(res, s1, len1 + 1);
	if (s2)
		ft_strlcpy(res + len1, s2, len2 + 1);
	return (res);
}

char	*ft_strdup(const char *s1)
{
	size_t	size;
	size_t	i;
	char	*ptr;

	i = 0;
	size = ft_strlen(s1);
	ptr = mallox(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	count;
	char	*res;

	i = 0;
	if (!s)
		return (NULL);
	count = ft_ft_strlen(s);
	if (start >= count)
		return (ft_strdup(""));
	if (len > count - start
		len >)
}