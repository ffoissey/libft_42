/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 17:50:54 by ffoissey          #+#    #+#             */
/*   Updated: 2020/04/22 16:55:49 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char			*ft_strctrim(char const *s, char c)
{
	const char	*tmp;
	char		*new_str;
	size_t		len;
	size_t		cp_len;

	if (!s)
		return (NULL);
	tmp = s;
	while (*tmp && *tmp == c)
		tmp++;
	len = ft_strlen(tmp);
	cp_len = len;
	while ((tmp[len - 1] == c) && len >= 1)
		len--;
	if (len == cp_len)
		return (ft_strdup(tmp));
	if (!(new_str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strncpy(new_str, tmp, len);
	new_str[len] = '\0';
	return (new_str);
}
