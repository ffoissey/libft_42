/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:28:12 by ffoissey          #+#    #+#             */
/*   Updated: 2020/04/22 18:06:23 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_strstr(const char *haystack, const char *needle)
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
		while (needle[j] == haystack[k] && needle[j])
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
