/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:26:55 by ffoissey          #+#    #+#             */
/*   Updated: 2018/11/19 18:06:59 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_output.h"

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putstr("-2147483648");
			return ;
		}
		write(1, "-", 1);
		ft_putnbr(-n);
	}
	else if (n <= 9)
		ft_putchar((char)(n + '0'));
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}
