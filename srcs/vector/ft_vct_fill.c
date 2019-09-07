/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:47:49 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/07 18:27:07 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

static void	vct_process_fill(t_vector *vct, char c, size_t nb, uint8_t opt)
{
	if (opt == FRONT)
	{
		ft_memmove(vct->str + nb, vct->str, vct->len);
		i = 0;
		goal = nb;
	}
	else
	{
		i = vct->len;
		goal = vct->len + nb;
	}
	while (i < goal)
	{
		vct->str[i] = c;
		i++;
	}
	vct->len += nb;
}

int			vct_fill(t_vector *vct, char c, size_t nb, uint8_t opt)
{
	size_t		i;
	size_t		goal;

	if (vct == NULL || nb == 0 || nb > VCT_LIMIT)
		return (FAILURE);
	if (vct->len + nb + 1 >= vct->size)
	{
		if (vct_extend(vct, vct->scale + nb) == FAILURE)
			return (FAILURE);
	}
	vct_process_fill(vct, c, nb, opt);
	return (SUCCESS);
}
