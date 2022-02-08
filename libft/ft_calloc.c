/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latahbah <latahbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:39:43 by latahbah          #+#    #+#             */
/*   Updated: 2021/10/11 20:49:31 by latahbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*res;
	size_t	i;

	i = 0;
	res = (void *)malloc(size * nmemb);
	if (res == NULL)
		return (NULL);
	while (i < size * nmemb)
	{
		res[i] = '\0';
		i++;
	}
	return ((void *)res);
}
