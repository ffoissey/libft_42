/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_pushstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 09:32:02 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/01 17:59:27 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_pushstr(t_vector *dest, char *src)
{
	size_t	i;
	size_t	src_len;

	if (dest == NULL || src == NULL || dest->str == NULL)
		return (SUCCESS);
	src_len = ft_strlen(src);
	if (dest->len + src_len + 1 >= dest->size)
	{
		if (vct_extend(dest, src_len + 1) == FAILURE)
			return (FAILURE);
	}
	ft_memmove(dest->str + src_len, dest->str, dest->size);
	i = 0;
	while (i < src_len)
	{
		dest->str[i] = src[i];
		i++;
	}
	dest->len += src_len;
	return (SUCCESS);
}
