/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_inttab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:12:38 by ffoissey          #+#    #+#             */
/*   Updated: 2018/11/12 11:12:39 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_output.h"

void	ft_print_inttab(int *tab, size_t size)
{
	size_t	i;

	i = 0;
	if (!tab || !size)
		return ;
	while (i < size)
	{
		ft_putnbr(tab[i]);
		if (i++ < (size - 1))
			ft_putstr(", ");
	}
	ft_putchar('\n');
}
