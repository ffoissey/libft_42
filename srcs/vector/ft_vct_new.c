/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 19:58:58 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/01 09:02:25 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector	*vct_new(size_t size)
{
	t_vector	*vct;

	if (size == 0)
		size = DFL_VCT_SIZE;
	vct = (t_vector *)malloc(sizeof(t_vector));
	if (vct != NULL)
	{
		vct->str = NULL;
		vct = vct_reset(vct);
	}
	return (vct);
}
