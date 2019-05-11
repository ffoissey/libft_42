/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:26:54 by ffoissey          #+#    #+#             */
/*   Updated: 2018/11/08 15:36:44 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new_str;

	if (!s)
		return (NULL);
	if (!(new_str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	new_str = ft_strncpy(new_str, s + start, len);
	new_str[len] = '\0';
	return (new_str);
}
