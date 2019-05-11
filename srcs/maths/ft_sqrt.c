/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:59:21 by ffoissey          #+#    #+#             */
/*   Updated: 2018/11/09 16:59:30 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_maths.h"

int		ft_sqrt(int nb)
{
	int		base;
	int		tmp;

	base = -1;
	if (nb <= 1000 && nb > 0)
	{
		while (++base <= nb)
		{
			if (base * base == nb)
				return (base);
		}
	}
	else if (nb <= 2147395600)
	{
		tmp = nb;
		if (nb > 100000 && nb <= 1000000)
			tmp = nb / 100;
		while (++base <= tmp)
		{
			if (base * base == nb)
				return (base);
		}
	}
	return (0);
}
