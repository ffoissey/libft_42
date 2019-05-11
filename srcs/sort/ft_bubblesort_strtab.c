/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubblesort_strtab.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:08:49 by ffoissey          #+#    #+#             */
/*   Updated: 2018/11/09 17:18:59 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"

void	ft_bubblesort_strtab(char **tab)
{
	char		*tmp;
	size_t		i;

	if (!tab || !*tab || !(tab + 1))
		return ;
	i = 0;
	while (tab[i + 1])
	{
		if (!tab[i] || !tab[i + 1])
			return ;
		if (ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}
