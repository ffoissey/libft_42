/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_cpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 09:18:16 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/11 17:01:54 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_cpy(t_vector *dest, t_vector *src)
{
	size_t	i;

	if (dest == NULL || src == NULL || dest->str == NULL || src->str == NULL)
		return (SUCCESS);
	if (src->len + 1 >= dest->size)
	{
		if (vct_extend(dest, src->len + 1) == FAILURE)
			return (FAILURE);
	}
	i = 0;
	while (i < src->len)
	{
		dest->str[i] = src->str[i];
		i++;
	}
	dest->str[i] = '\0';
	dest->len = src->len;
	return (SUCCESS);
}
