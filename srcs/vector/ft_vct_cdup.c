/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_cdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 09:41:51 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/01 12:59:40 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector	*vct_cdup(t_vector *vct, char c)
{
	t_vector	*new_vct;
	size_t		i;

	if (vct == NULL)
		return (NULL);
	i = 0;
	new_vct = vct_new(vct->size);
	while (i < vct->len && vct->str[i] != c)
	{
		new_vct->str[i] = vct->str[i];
		i++;
	}
	new_vct->scale = vct->scale;
	new_vct->len = i;
	return (new_vct);
}
