/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_cat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 09:18:16 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/12 17:36:27 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_cat(t_vector *dest, t_vector *src)
{
	size_t	i;
	size_t	j;

	if (dest == NULL || src == NULL || dest->str == NULL || src->str == NULL)
		return (SUCCESS);
	if (dest->len + src->len + 1 >= dest->size)
	{
		if (vct_extend(dest, src->len + 1) == FAILURE)
			return (FAILURE);
	}
	i = dest->len;
	j = 0;
	while (j < src->len)
		dest->str[i++] = src->str[j++];
	dest->str[i] = '\0';
	dest->len += src->len;
	return (SUCCESS);
}
