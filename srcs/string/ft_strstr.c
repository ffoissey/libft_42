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

#include "ft_string.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t		len_needle;
	char		*target;

	target = (char *)haystack;
	len_needle = ft_strlen((char *)len_needle);
	while (target != '\0')
	{
		if (ft_strnequ(target, needle, len_needle) == 1)
			return (target);
		target++;
	}
	return (NULL);
}
