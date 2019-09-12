/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_splitchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:23:53 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/12 15:35:45 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector	*vct_splitchr(t_vector *vct, char c)
{
	t_vector	*before;
	size_t		index;

	index = vct_chr(vct, c);
	before = vct_ndup(vct, index);
	vct_popfrom(vct, index + 1);
	return (before);
}
