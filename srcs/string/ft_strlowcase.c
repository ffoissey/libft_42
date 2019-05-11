/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:41:23 by ffoissey          #+#    #+#             */
/*   Updated: 2018/11/13 15:53:52 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strlowcase(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (ft_isupper(str[i]))
			str[i] += 32;
		i++;
	}
	return (str);
}
