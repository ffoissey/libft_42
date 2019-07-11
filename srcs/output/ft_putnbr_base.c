/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:10:20 by ffoissey          #+#    #+#             */
/*   Updated: 2018/11/19 18:08:36 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_output.h"

static int	check_base(char *base)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (base[i])
	{
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == '+' || base[i] == '-')
			return (1);
		j = 0;
		while (base[j])
		{
			if (base[i] == base[j] && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int			ft_putnbr_base(int nbr, char *base)
{
	int	ret;

	if (!(*base) || !(*(base + 1)) || check_base(base))
		return (-1);
	if (nbr < 0)
	{
		ret = write(1, "-", 1);
		if (nbr == -2147483648)
		{
			ret = ft_putnbr_base((nbr / (int)ft_strlen(base)) * -1, base);
			ret += ft_putchar(base[(nbr % (int)ft_strlen(base)) * -1]);
			return (ret);
		}
		ret = ft_putnbr_base(nbr * -1, base);
	}
	else if (nbr < (int)ft_strlen(base))
		ret = ft_putchar(base[nbr]);
	else
	{
		ret = ft_putnbr_base(nbr / (int)ft_strlen(base), base);
		ret = ft_putnbr_base(nbr % (int)ft_strlen(base), base);
	}
	return (ret);
}
