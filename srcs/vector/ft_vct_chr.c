/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_chr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:05:28 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/12 15:08:59 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

size_t	vct_chr(t_vector *vct, char c)
{
	size_t			i;

	i = 0;
	if (vct == NULL || vct->str == NULL)
		return (0);
	while (i < vct->len && vct->str[i] != c)
		i++;
	return (i);
}
