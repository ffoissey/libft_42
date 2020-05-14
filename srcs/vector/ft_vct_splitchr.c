/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_splitchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:23:53 by ffoissey          #+#    #+#             */
/*   Updated: 2020/05/14 20:24:17 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector	*vct_splitchr(t_vector *vct, char c, int flag)
{
	t_vector	*before;

	before = vct_cdup(vct, c);
	if (before != NULL)
	{
		if (vct_len(before) == vct_len(vct))
			flag = 0;
		vct_popfrom(vct, vct_len(before) + (size_t)flag);
	}
	return (before);
}
