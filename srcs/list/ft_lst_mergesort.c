/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_mergesort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 10:35:28 by ffoissey          #+#    #+#             */
/*   Updated: 2019/07/26 09:38:09 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static void			ft_mergesplit_lst(t_list *head, t_list **a, t_list **b)
{
	t_list	*fast;
	t_list	*slow;

	slow = head;
	fast = head->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*a = head;
	*b = slow->next;
	slow->next = NULL;
}

static t_list		*ft_process_merge(t_list *a, t_list *b,
						int (*test)(void *, void *))
{
	t_list	*result;

	if (a == NULL)
		return (b);
	if (b == NULL)
		return (a);
	result = NULL;
	if (test(a->content, b->content) == TRUE)
	{
		result = a;
		result->next = ft_process_merge(a->next, b, test);
	}
	else
	{
		result = b;
		result->next = ft_process_merge(a, b->next, test);
	}
	return (result);
}

void				ft_lst_mergesort(t_list **lst, int (*test)(void *, void *))
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	head = *lst;
	if (head == NULL || head->next == NULL)
		return ;
	ft_mergesplit_lst(head, &a, &b);
	ft_lst_mergesort(&a, test);
	ft_lst_mergesort(&b, test);
	*lst = ft_process_merge(a, b, test);
}
