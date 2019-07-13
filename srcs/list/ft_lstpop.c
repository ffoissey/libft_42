/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:01:46 by ffoissey          #+#    #+#             */
/*   Updated: 2018/11/08 19:20:00 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstpop(t_list **alst)
{
	t_list	*node;

	if (!alst || !*alst)
		return ;
	node = (*alst)->next;
	free(*alst);
	*alst = node;
}
