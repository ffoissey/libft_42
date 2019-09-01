/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_extend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 20:08:45 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/01 13:03:01 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_extend(t_vector *vct, size_t size)
{
	char	*str_tmp;

	if (size == 0 || vct == NULL)
		return (SUCCESS);
	size = size - size % vct->scale + vct->scale;
	vct->scale = size - vct->size;
	vct->size = size;
	str_tmp = vct->str; 
	vct->str = (char *)ft_memalloc(vct->size);
	if (vct->str == NULL)
		return (FAILURE);
	ft_memcpy((void *)vct->str, (void *)str_tmp, vct->len);
	ft_strdel(&str_tmp);
	return (SUCCESS);
}
