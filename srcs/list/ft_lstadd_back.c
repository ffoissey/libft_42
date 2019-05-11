/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:01:25 by ffoissey          #+#    #+#             */
/*   Updated: 2019/03/14 16:02:12 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*holder;

	if (!new)
		return ;
	holder = *alst == NULL ? NULL : *alst;
	if (holder)
	{
		while (holder->next != NULL)
			holder = holder->next;
		holder->next = new;
		return ;
	}
	*alst = new;
}
