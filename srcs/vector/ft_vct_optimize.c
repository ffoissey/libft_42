/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_optimize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 12:51:56 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/15 13:04:38 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_optimize(t_vector *vct)
{
	char	*str_tmp;

	if (vct == NULL)
		return (SUCCESS);
	if (vct->len * 3 < vct->size && vct->size > DFL_VCT_SIZE)
	{
		vct->size = vct->len % vct->scale + vct->len + vct->scale;
		vct->scale = vct->scale;
		str_tmp = vct->str;
		vct->str = (char *)ft_memalloc(vct->size);
		if (vct->str == NULL)
			return (FAILURE);
		ft_memcpy((void *)vct->str, (void *)str_tmp, vct->len);
		ft_strdel(&str_tmp);
	}
	return (SUCCESS);
}
