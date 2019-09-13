/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_fillfront.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:10:39 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/13 14:22:22 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_fillfront(t_vector *vct, char c, size_t nb)
{
	size_t		i;

	if (vct == NULL || vct->str == NULL || nb > VCT_LIMIT)
		return (FAILURE);
	if (vct->len + nb + 1 >= vct->size)
	{
		if (vct_extend(vct, vct->scale + nb) == FAILURE)
			return (FAILURE);
	}
	i = 0;
	ft_memmove(vct->str + nb, vct->str, vct->len);
	while (i < nb)
	{
		vct->str[i] = c;
		i++;
	}
	vct->len += nb;
	return (SUCCESS);
}
