/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:25:30 by ffoissey          #+#    #+#             */
/*   Updated: 2019/02/11 18:21:15 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_conversion.h"
#include <limits.h>

int		ft_atoi(const char *str)
{
	long		nbr;
	size_t		i;

	nbr = 0;
	i = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			break ;
		nbr = nbr * 10 + str[i++] - '0';
	}
	if (str[0] == '-')
	{
		if (nbr + 1 > LONG_MAX)
			return (0);
		return ((int)nbr * -1);
	}	
	if (nbr > LONG_MAX)
		return (-1);
	return ((int)nbr);
}
