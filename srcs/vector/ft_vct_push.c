/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 22:16:16 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/15 13:00:32 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_push(t_vector *vct, char c)
{
	if (vct == NULL)
		return (FAILURE);
	if (vct->len + 2 >= vct->size)
	{
		if (vct_extend(vct, vct->scale) == FAILURE)
			return (FAILURE);
	}
	ft_memmove(vct->str + 1, vct->str, vct->size - 1);
	vct->str[0] = c;
	vct->len++;
	vct_optimize(vct);
	return (SUCCESS);
}
