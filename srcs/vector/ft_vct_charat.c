/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_charat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:44:08 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/01 14:51:12 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_charat(t_vector *vct, char c, size_t index)
{
	if (vct == NULL)
		return (FAILURE);
	if (index >= vct->size)
	{
		if (vct_extend(vct, index - vct->size + vct->scale) == FAILURE)
			return (FAILURE);
		vct->len++;
		vct->str[index] = c;
		vct->str[index + 1] = '\0';
	}
	vct->str[index] = c;
	return (SUCCESS);
}
