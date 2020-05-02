/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_addcharat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:20:31 by ffoissey          #+#    #+#             */
/*   Updated: 2020/04/29 17:17:11 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_addcharat(t_vector *vct, char c, size_t index)
{
	if (vct == NULL || index > vct->len)
		return (FAILURE);
	if (vct->len + 2 >= vct->size)
	{
		if (vct_extend(vct, vct->scale) == FAILURE)
			return (FAILURE);
	}
	ft_memmove(vct->str + index + 1, vct->str + index, vct->len - index);
	vct->str[index] = c;
	vct->len++;
	vct_optimize(vct);
	return (SUCCESS);
}
