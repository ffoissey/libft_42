/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_neq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:14:34 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/13 14:20:01 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_neq(t_vector *vct1, t_vector *vct2, size_t nb)
{
	size_t	i;

	if (vct1 == NULL || vct2 == NULL || vct1->str == NULL || vct2->str == NULL)
		return (FALSE);
	if (vct1->len != vct2->len)
		return (FALSE);
	i = 0;
	while (i < nb && (i < vct1->len || i < vct2->len))
	{
		if (vct1->str[i] != vct2->str[i])
			return (FALSE);
		i++;
	}
	return (TRUE);
}
