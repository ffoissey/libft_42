/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_cutfrom.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 08:33:04 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/11 16:29:59 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_cutfrom(t_vector *vct, size_t index)
{
	size_t	i;

	if (vct == NULL)
		return (FAILURE);
	if (vct->len == 0 || index >= vct->len)
		return (SUCCESS);
	if (index == 0)
		vct_clear(vct);
	else
	{
		i = index - 1;
		while (i < vct->len)
			vct->str[i++] = '\0';
		vct->len = index;
	}
	return (SUCCESS);
}
