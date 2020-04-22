/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_bits.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:15:59 by ffoissey          #+#    #+#             */
/*   Updated: 2020/04/22 17:15:26 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_output.h"

int		ft_print_int_bits(int m)
{
	int		i;

	i = 31;
	while (i >= 0)
	{
		if (m >> i & 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		if (!(i % 8) && i != 0)
			write(1, " ", 1);
		i--;
	}
	return ((int)write(1, "\n", 1));
}
