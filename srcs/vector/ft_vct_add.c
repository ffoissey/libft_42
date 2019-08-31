/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 22:12:38 by ffoissey          #+#    #+#             */
/*   Updated: 2019/08/31 22:16:04 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_add(t_vector *vector, char c)
{
	if (vct->len + 1 >= vct->size)
	{
		if (vct_extend(vector, vct->scale) == FAILURE)
			return (FAILURE);
	}
	vct->str[vct->len] = c;
	vct->len++;
	return (SUCCESS);
}
