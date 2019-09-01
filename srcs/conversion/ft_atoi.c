/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:25:30 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/01 18:13:25 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_conversion.h"

int		ft_atoi(const char *str)
{
	int			nbr;
	size_t		i;

	nbr = 0;
	i = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && nbr + str[i] - '0')
		nbr = nbr * 10 + str[i++] - '0';
	return (str[0] == '-' ? -nbr : nbr);
}
