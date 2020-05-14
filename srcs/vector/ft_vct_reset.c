/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_reset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 20:04:11 by ffoissey          #+#    #+#             */
/*   Updated: 2020/05/14 20:23:58 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector	*vct_reset(t_vector *vct, size_t size)
{
	if (vct == NULL)
		return (NULL);
	if (size == 0)
		size = DFL_VCT_SIZE;
	ft_strdel(&vct->str);
	vct->str = (char *)ft_memalloc(size);
	if (vct->str == NULL)
	{
		free(vct);
		vct = NULL;
	}
	else
	{
		vct->size = size;
		vct->scale = DFL_VCT_SCALE;
		vct->len = 0;
	}
	return (vct);
}
