/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latahbah <latahbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 12:26:20 by latahbah          #+#    #+#             */
/*   Updated: 2021/10/10 14:30:16 by latahbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;
	size_t				i;

	if (dest == NULL && src == NULL)
		return (dest);
	d = (unsigned char *)dest;
	s = (unsigned const char *)src;
	i = 0;
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		d += n;
		s += n;
		while (n--)
		{
			d--;
			s--;
			*d = *s;
		}
	}
	return (dest);
}
