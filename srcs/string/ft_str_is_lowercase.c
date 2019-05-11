/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:36:20 by ffoissey          #+#    #+#             */
/*   Updated: 2018/11/13 14:36:22 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include <stdlib.h>

int		ft_str_is_lowercase(char *str)
{
	if (str == NULL)
		return (FALSE);
	while (*str != '\0')
	{
		if (ft_islower(*str) == FALSE)
			return (FALSE);
		str++;
	}
	return (TRUE);
}
