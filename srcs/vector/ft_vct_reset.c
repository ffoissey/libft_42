/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_reset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 20:04:11 by ffoissey          #+#    #+#             */
/*   Updated: 2019/08/31 20:08:19 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	vct_reset(t_vector *vct)
{
	if (vct == NULL)
		return ;
	ft_strdel(&vct->str);
	vct->size = DFL_VCT_SIZE;
	vct->scale = DFL_VCT_SCALE;
	vct->len = 0;
}
