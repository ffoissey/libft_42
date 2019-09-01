/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_ndup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 09:39:38 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/01 19:01:48 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector	*vct_ndup(t_vector *vct, size_t n)
{
	t_vector *new_vct;

	if (vct == NULL)
		return (NULL);
	if (n > vct->len)
		n = vct->len;
	new_vct = vct_new(vct->size);
	new_vct->scale = vct->scale;
	new_vct->len = n;
	if (n != 0)
		ft_strncpy(new_vct->str, vct->str, n);
	return (new_vct);
}
