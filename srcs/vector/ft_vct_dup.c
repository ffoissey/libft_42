/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 08:42:14 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/01 13:02:27 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector	*vct_dup(t_vector *vct)
{
	t_vector *new_vct;

	if (vct == NULL)
		return (NULL);
	new_vct = vct_new(vct->size);
	ft_memcpy(new_vct->str, vct->str, vct->len);
	new_vct->scale = vct->scale;
	new_vct->len = vct->len;
	return (new_vct);
}
