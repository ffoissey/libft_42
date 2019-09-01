/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_newstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 19:58:58 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/01 14:34:26 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector	*vct_newstr(char *str)
{
	t_vector	*vct;

	vct = (t_vector *)malloc(sizeof(t_vector));
	if (vct != NULL)
	{
		vct->str = NULL;
		vct = vct_reset(vct, DFL_VCT_SIZE);
		if (vct != NULL)
		{
			if (vct_addstr(vct, str) == FAILURE)
				vct_del(&vct);
		}
	}
	return (vct);
}
