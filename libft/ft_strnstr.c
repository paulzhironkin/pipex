/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latahbah <latahbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:04:07 by latahbah          #+#    #+#             */
/*   Updated: 2021/10/16 00:04:18 by latahbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*haystack2;
	const char	*needle2;
	size_t		len2;

	if (*needle == 0)
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		haystack2 = (const char *)haystack;
		needle2 = (const char *)needle;
		len2 = len;
		while (*haystack2 == *needle2 && *needle2 && len2 > 0)
		{
			haystack2++;
			needle2++;
			len2--;
		}
		if (*needle2 == '\0')
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
