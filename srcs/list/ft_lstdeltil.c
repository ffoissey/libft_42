/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdeltil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 15:31:31 by ffoissey          #+#    #+#             */
/*   Updated: 2020/04/12 15:31:49 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdeltil(t_list **alst, t_list *node, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (!alst || !*alst || !del)
		return ;
	while (*alst != node)
	{
		tmp = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = NULL;
		*alst = tmp;
	}
	*alst = node;
}
