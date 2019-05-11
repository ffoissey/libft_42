/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:19:52 by ffoissey          #+#    #+#             */
/*   Updated: 2018/11/13 15:36:19 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t tmp_size;
	size_t dst_len;
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	tmp_size = size;
	while (tmp_size-- && dst[i])
		i++;
	dst_len = i;
	tmp_size = size - dst_len;
	if (!tmp_size)
		return (dst_len + ft_strlen(src));
	while (src[j])
	{
		if (tmp_size != 1)
		{
			dst[i++] = src[j];
			tmp_size--;
		}
		j++;
	}
	dst[i] = '\0';
	return (dst_len + j);
}
