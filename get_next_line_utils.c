#include "get_next_line.h"

int	ft_strchr(const char *str, char c)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i] && str[i] != c)
		i++;
	if (str[i])
		return (i);
	return (-1);
}

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len1;
	int		len2;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if ((len1 + len2) == 0)
		return (NULL);
	res = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!res)
		return (NULL);
	if (s1)
		ft_strlcpy(res, s1, len1 + 1);
	if (s2)
		ft_strlcpy(res + len1, s2, len2 + 1);
	free(s1);
	return (res);
}

// char	*ft_strdup(const char *s1)
// {
// 	size_t	len;
// 	size_t	i;
// 	char	*ptr;

// 	i = 0;
// 	len = ft_strlen(s1);
// 	if (len == 0)
// 		return (NULL);
// 	ptr = malloc(sizeof(char) * (len + 1));
// 	if (!ptr)
// 		return (NULL);
// 	while (s1[i])
// 	{
// 		ptr[i] = s1[i];
// 		i++;
// 	}
// 	ptr[i] = '\0';
// 	return (ptr);
// }

// copies a string from the index start for len amount
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t char_count;
	char *res;

	if (!s)
		return (NULL);
	char_count = ft_strlen(s);
	if (start >= char_count)
		return (NULL);
	res = malloc(sizeof(char) * (char_count + 1));
	if (!res)
		return (NULL);
	while (s[start] != '\0' && start <= len) // <=?
	{
		res[start] = s[start];
		start++;
	}
	res[start] = '\0';
	return (res);
}