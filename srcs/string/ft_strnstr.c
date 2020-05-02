/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:27:03 by ffoissey          #+#    #+#             */
/*   Updated: 2020/04/22 18:08:58 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

const char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		k = i;
		while (needle[j] == haystack[k] && needle[j] && k < len)
		{
			j++;
			k++;
		}
		if (!needle[j])
			return (haystack + i);
		i++;
	}
	if (!len && !*needle)
		return (haystack);
	return (NULL);
}
