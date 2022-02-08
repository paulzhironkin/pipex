/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latahbah <latahbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:21:29 by latahbah          #+#    #+#             */
/*   Updated: 2021/10/10 12:24:43 by latahbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*tmp2;
	size_t			i;

	tmp = (unsigned char *)dest;
	tmp2 = (unsigned char *)src;
	i = 0;
	while (i < n && (tmp != NULL || tmp2 != NULL))
	{
		tmp[i] = tmp2[i];
		i++;
	}
	return (dest);
}
