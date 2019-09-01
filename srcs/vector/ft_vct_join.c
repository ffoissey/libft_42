/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 08:52:55 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/01 09:26:53 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector	*vct_join(t_vector *vct1, t_vector *vct2)
{
	t_vector	*new_vct;
	size_t		i;

	if (vct1 == NULL && vct2 == NULL)
		return (NULL);
	else if (vct1 == NULL)
		return (vct_dup(vct2));
	else if (vct2 == NULL)
		return (vct_dup(vct1));
	else 
	{
		new_vct = vct_new(vct1->size + vct2->size + 1);
		new_vct->scale = vct1->scale > vct2->scale ? vct1->scale : vct2->scale;
		new_vct->len = vct1->len + vct2->len;
		vct_cpy(new_vct, vct1);
		vct_cat(new_vct, vct2);
	}
	return (new_vct);
}
