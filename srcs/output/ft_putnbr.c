/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:26:55 by ffoissey          #+#    #+#             */
/*   Updated: 2019/08/29 21:46:39 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_output.h"

int		ft_putnbr(int n)
{
	int		ret;

	if (n < 0)
	{
		if (n == -2147483648)
		{
			ret = ft_putstr("-2147483648");
			return (ret);
		}
		ret = write(1, "-", 1);
		ret = ft_putnbr(-n);
	}
	else if (n <= 9)
		ret = ft_putchar((char)(n + '0'));
	else
	{
		ret = ft_putnbr(n / 10);
		ret = ft_putnbr(n % 10);
	}
	return (ret);
}
