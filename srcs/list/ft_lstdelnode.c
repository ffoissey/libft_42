/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelnode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 09:38:27 by ffoissey          #+#    #+#             */
/*   Updated: 2019/07/26 09:41:15 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static int	first_node(t_list **lst, void *data, void (*del)(void *))
{
	t_list	*run;

	run = *lst;
	if (run->content == data)
	{
		*lst = (*lst)->next;
		if (del != NULL)
			del(run->content);
		free(run);
		return (TRUE);
	}
	return (FALSE);
}

void		ft_lstdelnode(t_list **lst, void *data, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*run;

	if (lst == NULL || *lst == NULL || data == NULL)
		return ;
	if (first_node(lst, data, del) == TRUE)
		return ;
	run = *lst;
	tmp = run;
	while (run != NULL)
	{
		if (run->content == data)
		{
			tmp->next = run->next;
			if (del != NULL)
				del(run->content);
			free(run);
			return ;
		}
		tmp = run;
		run = run->next;
	}
}
