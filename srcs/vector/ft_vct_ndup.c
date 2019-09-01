/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_ndup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 09:39:38 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/01 13:04:12 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector	*vct_ndup(t_vector *vct, size_t n)
{
	t_vector *new_vct;

	if (vct == NULL || n == 0)
		return (NULL);
	new_vct = vct_new(vct->size);
	ft_strncpy(new_vct->str, vct->str, n);
	new_vct->scale = vct->scale;
	new_vct->len = n;
	return (new_vct);
}

