/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 15:16:36 by ffoissey          #+#    #+#             */
/*   Updated: 2020/04/22 16:56:29 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include "ft_string.h"
#include <string.h>

char	*ft_strcapitalize(char *str)
{
	size_t	i;

	if (str == NULL)
		return (NULL);
	i = 0;
	str[i] = (char)ft_toupper(str[i]);
	i++;
	while (str[i] != '\0')
	{
		if (ft_islower(str[i]) == TRUE && ft_isalnum(str[i - 1]) == FALSE)
			str[i] -= 32;
		else if (ft_isupper(str[i]) == TRUE && ft_isalnum(str[i - 1]) == TRUE)
			str[i] += 32;
		i++;
	}
	return (str);
}
