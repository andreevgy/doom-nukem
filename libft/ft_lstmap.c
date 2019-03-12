/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmacgyve <fmacgyve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 10:26:55 by fmacgyve          #+#    #+#             */
/*   Updated: 2018/12/05 15:14:05 by fmacgyve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *first;
	t_list *tmp;
	t_list *newelem;

	if (!lst || !f)
		return (NULL);
	newelem = f(lst);
	lst = lst->next;
	first = newelem;
	while (lst)
	{
		tmp = f(lst);
		newelem->next = tmp;
		newelem = newelem->next;
		lst = lst->next;
	}
	return (first);
}
