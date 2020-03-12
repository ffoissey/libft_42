/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_splitchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:23:53 by ffoissey          #+#    #+#             */
/*   Updated: 2020/03/12 14:52:58 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector	*vct_splitchr(t_vector *vct, char c)
{
	t_vector	*before;
	ssize_t		index;

	index = vct_chr(vct, c);
	if (index == FAILURE)
		index = (ssize_t)vct->len;
	before = vct_ndup(vct, index);
	vct_popfrom(vct, index + 1);
	return (before);
}
