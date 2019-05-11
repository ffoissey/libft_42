/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertsort_integer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:12:51 by ffoissey          #+#    #+#             */
/*   Updated: 2018/11/12 11:12:53 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"

static void	ft_insert_elem(int *tab, size_t i, size_t j)
{
	size_t	n;
	int		tmp;

	n = 0;
	tmp = tab[i];
	while (n < (i - (j - 1)))
	{
		tab[i - n] = tab[i - (n + 1)];
		n++;
	}
	tab[i - n] = tmp;
}

void		ft_insertsort_integer(int *tab, size_t size)
{
	size_t	i;
	size_t	j;

	if (!tab)
		return ;
	i = 0;
	while (++i < size)
	{
		j = 0;
		while (j < i)
		{
			if (tab[i] < tab[j++])
				ft_insert_elem(tab, i, j);
		}
	}
}

static void	ft_insert_elem_long(long *tab, size_t i, size_t j)
{
	size_t	n;
	int		tmp;

	n = 0;
	tmp = tab[i];
	while (n < (i - (j - 1)))
	{
		tab[i - n] = tab[i - (n + 1)];
		n++;
	}
	tab[i - n] = tmp;
}

void		ft_insertsort_long(long *tab, size_t size)
{
	size_t	i;
	size_t	j;

	if (!tab)
		return ;
	i = 0;
	while (++i < size)
	{
		j = 0;
		while (j < i)
		{
			if (tab[i] < tab[j++])
				ft_insert_elem_long(tab, i, j);
		}
	}
}
