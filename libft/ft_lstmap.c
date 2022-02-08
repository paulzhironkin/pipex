/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latahbah <latahbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:36:16 by latahbah          #+#    #+#             */
/*   Updated: 2021/10/14 21:51:12 by latahbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *list, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*res;
	t_list	*tmp;
	void	*cont;

	res = NULL;
	tmp = list;
	while (list)
	{
		cont = f(list->content);
		new = ft_lstnew(cont);
		if (new == NULL && res != NULL)
			ft_lstclear(&res, free);
		ft_lstadd_back(&res, new);
		list = list->next;
	}
	ft_lstclear(&list, del);
	return (res);
}
