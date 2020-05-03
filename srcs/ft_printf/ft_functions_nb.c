/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_nb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 12:42:17 by ffoissey          #+#    #+#             */
/*   Updated: 2020/04/28 20:43:09 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_str(char *str, long nbr, size_t *i, int base)
{
	if (nbr < 0)
	{
		if (base == 10)
		{
			str[(*i)++] = '-';
			if (nbr < -9223372036854775807)
			{
				str[1] = '9';
				nbr /= 10;
				(*i)++;
			}
		}
		fill_str(str, nbr * -1, i, base);
	}
	else if (nbr < base)
	{
		str[*i] = nbr < 10 ? (char)nbr + '0' : (char)nbr % 10 + 'A';
		(*i)++;
	}
	else
	{
		fill_str(str, nbr / base, i, base);
		fill_str(str, nbr % base, i, base);
	}
}

char		*ft_itoa_base_l(long value, int base)
{
	size_t		i;
	long		tmp;
	char		*str;

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
	fill_str(str, value, &i, base);
	str[i] = '\0';
	return (str);
}

static void	fill_str_lu(char *str, unsigned long nbr,
			size_t *i, unsigned int base)
{
	if (nbr < base)
	{
		if (nbr < 10)
			str[*i] = (char)nbr + '0';
		else
			str[*i] = (char)nbr % 10 + 'A';
		(*i)++;
	}
	else if (base != 0)
	{
		fill_str_lu(str, nbr / base, i, base);
		fill_str_lu(str, nbr % base, i, base);
	}
}

char		*ft_itoa_base_lu(unsigned long value, unsigned int base)
{
	size_t			i;
	unsigned long	tmp;
	char			*str;

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
	fill_str_lu(str, value, &i, base);
	str[i] = '\0';
	return (str);
}
