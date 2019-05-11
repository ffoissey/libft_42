/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:39:07 by ffoissey          #+#    #+#             */
/*   Updated: 2018/11/13 14:40:43 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include <stdlib.h>

int		ft_str_is_numeric(char *str)
{
	if (str == NULL)
		return (FALSE);
	while (*str != '\0')
	{
		if (ft_isdigit(*str) == FALSE)
			return (FALSE);
		str++;
	}
	return (TRUE);
}
