/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_splitchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:23:53 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/11 15:49:13 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector	*vct_splitchr(t_vector *vct, char c)
{
	char		*search;
	t_vector	*before;
	size_t		size;

	before = vct_dup(vct);
	search = ft_strchr(vct->str, c);
	if (search == NULL)
		vct_clear(vct);
	else
	{
		size = search - vct->str;
		vct_popfrom(vct, size + 1);	
		if (size == 0)
			vct_clear(before);
		else
			vct_cutfrom(before, size);
	}
	return (before);
}
