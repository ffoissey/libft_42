/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_addmemat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 17:25:52 by ffoissey          #+#    #+#             */
/*   Updated: 2020/04/12 17:53:05 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_addmemat(t_vector *vct, char *str, size_t len, size_t index)
{
	size_t	i;

	if (vct == NULL || str == NULL)
		return (FAILURE);
	if (vct->len + index + len + 1 >= vct->size)
	{
		if (vct_extend(vct, len + vct->scale) == FAILURE)
			return (FAILURE);
	}
	i = 0;
	while (i < len)
	{
		vct->str[i + index] = str[i];
		i++;
	}
	vct->len += len;
	return (SUCCESS);
}
