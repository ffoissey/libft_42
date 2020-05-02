/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:18:43 by ffoissey          #+#    #+#             */
/*   Updated: 2020/04/22 18:05:55 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

const char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	c_cp;

	i = 0;
	c_cp = (unsigned char)c;
	while (s[i])
	{
		if (c_cp == s[i])
			return (s + i);
		i++;
	}
	return ((s[i] == c_cp) ? (s + i) : NULL);
}
