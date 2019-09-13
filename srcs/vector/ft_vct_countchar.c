/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_countchar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:46:55 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/13 15:52:05 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

size_t		vct_countchar(t_vector *vct, char c)
{
	size_t	i;
	size_t	count;

	if (vct == NULL || vct->str == NULL)
		return (FAILURE);
	i = 0;
	count = 0;
	while (i < vct->len)
	{
		if (vct->str[i] == c)
			count++;
		i++;
	}
	return (count);
}
