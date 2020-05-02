/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasestr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:29:42 by ffoissey          #+#    #+#             */
/*   Updated: 2020/04/22 18:08:31 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static unsigned char	ft_cmp_char(const char c1, const char c2)
{
	unsigned char c1_tmp;
	unsigned char c2_tmp;

	c1_tmp = (unsigned char)ft_toupper(c1);
	c2_tmp = (unsigned char)ft_toupper(c2);
	return (c1_tmp == c2_tmp);
}

const char				*ft_strcasestr(const char *haystack, const char *needle)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = 0;
	while (haystack[i])
	{
		j = 0;
		k = i;
		while (ft_cmp_char(needle[j], haystack[k]) && needle[j])
		{
			j++;
			k++;
		}
		if (!needle[j])
			return (haystack + i);
		i++;
	}
	return ((haystack[i] == needle[j]) ? (haystack + i) : NULL);
}
