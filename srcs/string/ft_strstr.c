/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:28:12 by ffoissey          #+#    #+#             */
/*   Updated: 2018/11/13 17:31:42 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
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
			return ((char *)(haystack + i));
		i++;
	}
	return ((haystack[i] == needle[j]) ? ((char *)(haystack + i)) : NULL);
}
