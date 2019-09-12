/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_popfrom.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 08:36:52 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/12 15:18:34 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_popfrom(t_vector *vct, size_t index)
{
	size_t	len;
	size_t	i;

	if (vct == NULL)
		return (FAILURE);
	if (vct->len == 0 || index == 0)
		return (SUCCESS);
	if (index >= vct->len)
		vct_clear(vct);
	else
	{
		len = vct->len - index;
		ft_memmove(vct->str, vct->str + index, len);
		i = len;
		while (i < vct->len)
			vct->str[i++] = '\0';
		vct->len = len;
	}
	return (SUCCESS);
}
