/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:37:01 by ffoissey          #+#    #+#             */
/*   Updated: 2018/11/13 14:39:20 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include <stdlib.h>

int		ft_str_is_uppercase(char *str)
{
	if (str == NULL)
		return (FALSE);
	while (*str != '\0')
	{
		if (ft_isupper(*str) == FALSE)
			return (FALSE);
		str++;
	}
	return (TRUE);
}
