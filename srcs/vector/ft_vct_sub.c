/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_sub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 11:57:29 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/01 19:34:51 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector	*vct_sub(t_vector *vct, size_t start, size_t end)
{
	t_vector	*new_vct;

	if (vct == NULL || vct->str == NULL || start >= vct->len || end <= start)
		return (NULL);
	if (end > vct->len)
		end = vct->len;
	new_vct = vct_new(vct->size);
	new_vct->len = end - start;
	ft_strncpy(new_vct->str, vct->str + start, new_vct->len);
	return (new_vct);
}
