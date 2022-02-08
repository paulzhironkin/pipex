/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latahbah <latahbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:48:30 by latahbah          #+#    #+#             */
/*   Updated: 2021/10/14 12:04:10 by latahbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	num;

	num = (long int)n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num *= -1;
	}
	if (num >= 0 && num <= 9)
	{
		ft_putchar_fd((char)(num % 10 + '0'), fd);
	}
	else
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putchar_fd((char)(num % 10 + '0'), fd);
		num /= 10;
	}
}
