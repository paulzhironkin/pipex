/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latahbah <latahbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:39:28 by latahbah          #+#    #+#             */
/*   Updated: 2022/02/08 18:21:38 by latahbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**alloc_arr(char const *s, char c, int *size)
{
	char	**res;

	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
			*size = *size + 1;
		while (*s != c && *s)
			s++;
	}
	res = (char **)malloc(sizeof(char *) * (*size + 1));
	return (res);
}

static char	**handle(char **res, int i)
{
	while (i)
	{
		free(res[i]);
		i--;
	}
	free(res);
	return (NULL);
}

static char	**alloc_str(char **res, char const *s, char c, int *size)
{
	int	str_size;
	int	i;

	i = 0;
	while (*s && i < *size)
	{
		while (*s == c && *s)
			s++;
		str_size = 0;
		while (*s != c && *s)
		{
			str_size++;
			s++;
		}
		res[i] = (char *)malloc(sizeof(char) * (str_size + 1));
		if (res[i] == NULL)
		{
			return (handle(res, i - 1));
		}
		i++;
	}
	res[i] = NULL;
	return (res);
}

static char	**fill_arr(char **res, char const *s, char c, int *size)
{
	int	i;
	int	j;

	i = 0;
	while (i < *size && *s)
	{
		while (*s == c && *s)
			s++;
		j = 0;
		while (*s != c && *s)
		{
			res[i][j] = *s;
			j++;
			s++;
		}
		res[i][j] = '\0';
		i++;
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		size;

	size = 0;
	if (s == NULL)
		return (NULL);
	res = alloc_arr(s, c, &size);
	if (res == NULL)
		return (NULL);
	res = alloc_str(res, s, c, &size);
	if (res == NULL)
		return (NULL);
	res = fill_arr(res, s, c, &size);
	return (res);
}
