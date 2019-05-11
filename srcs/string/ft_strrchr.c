/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:27:30 by ffoissey          #+#    #+#             */
/*   Updated: 2018/11/12 12:19:49 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	size_t			j;
	unsigned char	c_cp;

	i = 0;
	c_cp = (unsigned char)c;
	if (!c_cp)
		return ((char *)s + ft_strlen(s));
	while (s[i])
	{
		if (c_cp == s[i])
		{
			j = i + 1;
			while (s[j] && s[j] != c_cp)
				j++;
			if (!s[j])
				return ((char *)(s + i));
		}
		i++;
	}
	return ((s[i] == c_cp) ? ((char *)s + i) : NULL);
}
