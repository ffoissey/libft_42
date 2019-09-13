/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_chr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:05:28 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/13 13:43:28 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

ssize_t	vct_chr(t_vector *vct, char c)
{
	ssize_t			i;

	i = 0;
	if (vct == NULL || vct->str == NULL)
		return (0);
	while ((size_t)i < vct->len && vct->str[i] != c)
		i++;
	if ((size_t)i == vct->len)
		i = FAILURE;
	return (i);
}
