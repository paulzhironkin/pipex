/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latahbah <latahbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:54:04 by latahbah          #+#    #+#             */
/*   Updated: 2021/10/14 16:26:50 by latahbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **list, void (*del)(void*))
{
	t_list	*tmp;

	while ((*list))
	{
		if ((*list)->content)
			del((*list)->content);
		tmp = *list;
		*list = (*list)->next;
		free(tmp);
	}
}
