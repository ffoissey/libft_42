/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_addnstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:32:36 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/12 14:59:07 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_addnstr(t_vector *dest, char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (dest == NULL || src == NULL || dest->str == NULL)
		return (SUCCESS);
	if (dest->len + size + 1 >= dest->size)
	{
		if (vct_extend(dest, size + 1) == FAILURE)
			return (FAILURE);
	}
	i = dest->len;
	j = 0;
	while (j < size)
		dest->str[i++] = src[j++];
	dest->str[i] = '\0';
	dest->len += size;
	return (SUCCESS);
}
