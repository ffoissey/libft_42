/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertsort_strtab.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:27:49 by ffoissey          #+#    #+#             */
/*   Updated: 2018/11/28 17:28:12 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"

static void	ft_insert_elem(char **tab, size_t i, size_t j)
{
	size_t	n;
	char	*tmp;

	n = 0;
	tmp = tab[i];
	while (n < (i - (j - 1)))
	{
		tab[i - n] = tab[i - (n + 1)];
		n++;
	}
	tab[i - n] = tmp;
}

void		ft_insertsort_strtab(char **tab)
{
	size_t	i;
	size_t	j;

	if (!tab || !(tab + 1))
		return ;
	i = 0;
	while (tab[++i])
	{
		j = 0;
		while (j < i)
		{
			if (ft_strcasecmp(tab[i], tab[j++]) < 0)
				ft_insert_elem(tab, i, j);
		}
	}
}
