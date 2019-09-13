/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_clen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:22:55 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/13 14:25:47 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

size_t	vct_clen(t_vector *vct, char c)
{
	size_t	i;

	if (vct == NULL)
		return (0);
	i = 0;
	while (i < vct->len)
	{
		if (vct->str[i] == c)
			break ;
		i++;
	}
	return (i);
}
