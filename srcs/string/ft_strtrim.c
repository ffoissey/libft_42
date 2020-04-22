/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:53:55 by ffoissey          #+#    #+#             */
/*   Updated: 2020/04/22 16:55:20 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char			*ft_strtrim(char const *s)
{
	const char	*tmp;
	char		*new_str;
	size_t		len;
	size_t		cp_len;

	if (!s)
		return (NULL);
	tmp = s;
	while (*tmp && (*tmp == ' ' || *tmp == '\t' || *tmp == '\n'))
		tmp++;
	len = ft_strlen(tmp);
	cp_len = len;
	while ((tmp[len - 1] == ' ' || tmp[len - 1] == '\t' || tmp[len - 1] == '\n')
			&& len >= 1)
		len--;
	if (len == cp_len)
		return (ft_strdup(tmp));
	if (!(new_str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strncpy(new_str, tmp, len);
	new_str[len] = '\0';
	return (new_str);
}
