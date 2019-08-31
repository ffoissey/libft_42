/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 22:16:16 by ffoissey          #+#    #+#             */
/*   Updated: 2019/08/31 22:20:32 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_push(t_vector *vector, char c)
{
	if (vct->len + 1 >= vct->size)
	{
		if (vct_extend(vector, vct->scale) == FAILURE)
			return (FAILURE);
	}
	ft_memmove(vct->str + 1, vct->str, vct->len);
	vct->str[0] = c;
	vct->len++;
	return (SUCCESS);
}
