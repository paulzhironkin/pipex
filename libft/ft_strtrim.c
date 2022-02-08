/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latahbah <latahbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:59:36 by latahbah          #+#    #+#             */
/*   Updated: 2021/10/13 17:39:47 by latahbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check_edges(int *start, int *end, int i)
{
	if (*start == *end)
		start = end;
	else if (*start == -1)
		*start = *start + 1;
	else if (*end == -1)
		*end = i - 1;
}

static void	find_edges(int *start, int *end, char const *s1, char const *set)
{
	int	mark;
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		mark = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				mark++;
			j++;
		}
		if (mark == 0 && *start == -1)
			*start = i;
		else if (mark == 0)
			*end = i;
		i++;
	}
	check_edges(start, end, i);
}

static char	*fill_str(char const *s1, char *str, int start, int end)
{
	int	i;

	i = 0;
	while (i < end - start + 1)
	{
		str[i] = s1[start + i];
		i++;
	}
	str[i] = '\0';
	return (&str[0]);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;

	start = -1;
	end = -1;
	if (s1 == NULL || set == NULL)
		return (NULL);
	find_edges(&start, &end, s1, set);
	if (start == end)
	{
		str = ft_strdup("");
		return (str);
	}
	str = (char *)malloc(sizeof(char) * (end - start + 2));
	if (str == NULL)
		return (NULL);
	return (fill_str(s1, str, start, end));
}
