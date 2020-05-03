/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_delchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:44:08 by ffoissey          #+#    #+#             */
/*   Updated: 2020/04/29 17:33:13 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_delchar(t_vector *vct, size_t index)
{
	if (vct == NULL)
		return (FAILURE);
	if (index + 1 == vct->len)
		vct_cut(vct);
	else if (index == 0)
		vct_pop(vct);
	else if (index + 1 < vct->len)
	{
		ft_memmove(vct->str + index, vct->str + index + 1,
				vct->len - index + 1);
		vct->str[vct->len - 1] = '\0';
		vct->len--;
	}
	return (SUCCESS);
}
