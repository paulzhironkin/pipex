/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latahbah <latahbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:30:05 by latahbah          #+#    #+#             */
/*   Updated: 2021/10/13 18:36:10 by latahbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

static char	*fill_str(char *str, int size, int pol, int n)
{
	str[size - 1] = '\0';
	size--;
	while (size--)
	{
		if (size == 0 && pol == 1)
		{
			str[size] = '-';
		}
		else
		{	
			str[size] = n % 10 + '0';
			n /= 10;
		}
	}
	return (str);
}

static void	check_pol(int *n, int *size, int *pol)
{
	int		nn;

	if (*n < 0)
	{
		*pol = 1;
		*n *= -1;
		*size = *size + 1;
	}
	else
		*pol = 0;
	nn = *n;
	while (nn > 0)
	{
		*size = *size + 1;
		nn /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;
	int		pol;

	size = 1;
	if (n == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	if (n == -2147483647 - 1)
	{
		str = ft_strdup("-2147483648");
		return (str);
	}
	check_pol(&n, &size, &pol);
	str = (char *)malloc(sizeof(char) * (size));
	if (str == NULL)
		return (NULL);
	return (fill_str(str, size, pol, n));
}
