/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 13:37:25 by exam              #+#    #+#             */
/*   Updated: 2018/11/13 15:39:19 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_conversion.h"
#include "ft_string.h"
#include <stdlib.h>

static void	fill_str(char *str, long nbr, size_t *i, int base)
{
	if (nbr < 0)
	{
		if (base == 10)
		{
			str[*i] = '-';
			(*i)++;
		}
		fill_str(str, nbr * -1, i, base);
	}
	else if (nbr < base)
	{
		if (nbr < 10)
			str[*i] = (char)nbr + '0';
		else
			str[*i] = (char)nbr % 10 + 'A';
		(*i)++;
	}
	else
	{
		fill_str(str, nbr / base, i, base);
		fill_str(str, nbr % base, i, base);
	}
}

char		*ft_itoa_base(int value, int base)
{
	size_t	i;
	int		tmp;
	char	*str;

	i = 0;
	if (value <= 0)
		i++;
	tmp = value;
	while (tmp)
	{
		tmp /= base;
		i++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	fill_str(str, (long)value, &i, base);
	str[i] = '\0';
	return (str);
}
