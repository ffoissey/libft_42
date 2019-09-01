/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 22:12:38 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/01 09:11:53 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_add(t_vector *vector, char c)
{
	if (vct == NULL)
		return (FAILURE);
	if (vct->len + 2 >= vct->size)
	{
		if (vct_extend(vector, vct->scale) == FAILURE)
			return (FAILURE);
	}
	vct->str[vct->len] = c;
	vct->str[vct->len + 1] = '\0';
	vct->len++;
	return (SUCCESS);
}
