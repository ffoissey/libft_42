/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_addstrat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:24:01 by ffoissey          #+#    #+#             */
/*   Updated: 2020/04/30 20:23:57 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_addstrat(t_vector *vct, char *str, size_t index)
{
	size_t	len;
	size_t	i;

	if (vct == NULL || str == NULL || index > vct->len)
		return (FAILURE);
	len = ft_strlen(str);
	if (vct->len + len + 1 >= vct->size)
	{
		if (vct_extend(vct, len + vct->scale) == FAILURE)
			return (FAILURE);
	}
	ft_memmove(vct->str + index + len, vct->str + index, vct->len - index);
	i = 0;
	while (i < len)
	{
		vct->str[i + index] = str[i];
		i++;
	}
	vct->len += len;
	vct_optimize(vct);
	return (SUCCESS);
}
