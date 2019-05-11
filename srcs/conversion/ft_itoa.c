/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:09:42 by ffoissey          #+#    #+#             */
/*   Updated: 2018/11/07 19:14:16 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_conversion.h"
#include "ft_string.h"
#include <stdlib.h>

static void	ft_strnbr(int nbr, char *str, int *i)
{
	if (nbr < 0)
	{
		str[*i] = '-';
		(*i)++;
		ft_strnbr(-nbr, str, i);
	}
	else if (nbr <= 9)
	{
		str[*i] = (char)(nbr + '0');
		(*i)++;
	}
	else
	{
		ft_strnbr(nbr / 10, str, i);
		ft_strnbr(nbr % 10, str, i);
	}
}

char		*ft_itoa(int n)
{
	int		tmp;
	size_t	size;
	char	*str;
	int		i;

	i = 0;
	tmp = n;
	size = 0;
	if (n <= 0)
		size = 1;
	while (tmp)
	{
		tmp /= 10;
		size++;
	}
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_strnbr(n, str, &i);
	str[size] = '\0';
	return (str);
}
