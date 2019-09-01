/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 22:12:38 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/01 15:10:31 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_add(t_vector *vct, char c)
{
	if (vct == NULL)
		return (FAILURE);
	if (vct->len + 1 >= vct->size)
	{
		if (vct_extend(vct, vct->scale) == FAILURE)
			return (FAILURE);
	}
	vct->str[vct->len] = c;
	vct->str[vct->len + 1] = '\0';
	vct->len++;
	return (SUCCESS);
}
