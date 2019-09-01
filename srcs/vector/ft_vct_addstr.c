/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_addstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 09:30:14 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/01 15:09:07 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_addstr(t_vector *dest, char *src)
{
	size_t	i;
	size_t	j;
	size_t	src_len;

	if (dest == NULL || src == NULL || dest->str == NULL)
		return (SUCCESS);
	src_len = ft_strlen(src);
	if (dest->len + src_len + 1 >= dest->size)
	{
		if (vct_extend(dest, src_len + 1) == FAILURE)
			return (FAILURE);
	}
	i = dest->len;
	j = 0;
	while (j < src_len)
		dest->str[i++] = src[j++];
	dest->str[i] = '\0';
	dest->len += src_len;
	return (SUCCESS);
}
