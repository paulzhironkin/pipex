/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latahbah <latahbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 23:01:50 by latahbah          #+#    #+#             */
/*   Updated: 2022/02/19 23:06:41 by latahbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(sizeof(const char) * (ft_strlen(s) + 1));
	if (str == NULL)
		return (NULL);
	while (i < ft_strlen(s))
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size;
	size_t	i;
	size_t	j;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (&str[0]);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	if (!*str1 && *str2)
	{
		return (-1);
	}
	while (n--)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
		if (!*str1 && n != 0)
			return (*str1 - *str2);
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		return (ft_strdup(""));
	}
	if (len > ft_strlen(s))
		str = (char *)malloc(sizeof(char) * ((int)ft_strlen(s) + 1));
	else
		str = (char *)malloc(sizeof(char) * ((len + 1)));
	if (str == NULL)
		return (NULL);
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (&str[0]);
}
