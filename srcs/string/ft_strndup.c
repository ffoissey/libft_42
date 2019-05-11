/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:52:21 by ffoissey          #+#    #+#             */
/*   Updated: 2018/11/13 11:22:06 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*new_str;
	size_t	len;

	len = ft_strnlen(s1, n);
	if (!(new_str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strncpy(new_str, s1, len);
	new_str[len] = '\0';
	return (new_str);
}
