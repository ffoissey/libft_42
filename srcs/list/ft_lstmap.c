/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:50:03 by ffoissey          #+#    #+#             */
/*   Updated: 2018/11/09 11:06:22 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*start;

	if (!lst || !f)
		return (NULL);
	if (!(new_lst = f(lst)))
		return (NULL);
	start = new_lst;
	lst = lst->next;
	while (lst)
	{
		if (!(new_lst->next = f(lst)))
			return (NULL);
		lst = lst->next;
		new_lst = new_lst->next;
	}
	return (start);
}
