/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_fillback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:10:20 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/13 14:22:23 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_fillback(t_vector *vct, char c, size_t nb)
{
	size_t		i;
	size_t		goal;

	if (vct == NULL || vct->str == NULL || nb > VCT_LIMIT)
		return (FAILURE);
	if (vct->len + nb + 1 >= vct->size)
	{
		if (vct_extend(vct, vct->scale + nb) == FAILURE)
			return (FAILURE);
	}
	i = vct->len;
	goal = vct->len + nb;
	while (i < goal)
	{
		vct->str[i] = c;
		i++;
	}
	vct->str[i] = '\0';
	vct->len += nb;
	return (SUCCESS);
}
