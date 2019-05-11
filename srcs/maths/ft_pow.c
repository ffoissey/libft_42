/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:10:53 by ffoissey          #+#    #+#             */
/*   Updated: 2018/11/13 15:54:48 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_maths.h"

static unsigned long	ft_pow_inter(unsigned long n, int p)
{
	if (!p)
		return (1);
	if ((n *= ft_pow_inter(n, p - 1)) > 2147483647)
		return (0);
	return (n);
}

int						ft_pow(int n, int p)
{
	unsigned long	n_l;
	int				res;

	if (!n)
		return (0);
	if (!p || n == 1)
		return (1);
	if (p < 0 || p > 30)
		return (-1);
	if (n > 0)
		(n_l = (unsigned long)n);
	else
		(n_l = -(unsigned long)n);
	res = (int)ft_pow_inter(n_l, p);
	if (res <= 0)
		return (-1);
	return (((p % 2) && n < 0) ? -res : res);
}
