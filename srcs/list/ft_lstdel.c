/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:24:40 by ffoissey          #+#    #+#             */
/*   Updated: 2020/05/03 16:03:49 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (!alst || !*alst)
		return ;
	while (*alst)
	{
		tmp = (*alst)->next;
		if (del != NULL)
			del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = NULL;
		*alst = tmp;
	}
}
