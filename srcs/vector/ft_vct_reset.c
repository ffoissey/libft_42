/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_reset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 20:04:11 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/01 09:02:22 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector *vct_reset(t_vector *vct)
{
	if (vct == NULL)
		return (NULL);
	ft_strdel(&vct->str);
	vct->str = (char *)ft_memalloc(DFL_VCT_SIZE);
	if (vct->str == NULL)
	{
		free(vct);
		vct = NULL;
	}
	else
	{
		vct->size = DFL_VCT_SIZE;
		vct->scale = DFL_VCT_SCALE;
		vct->len = 0;
	}
	return (vct);
}
