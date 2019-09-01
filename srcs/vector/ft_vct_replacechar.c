/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_replacechar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 12:07:22 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/01 13:05:54 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	vct_replacechar(t_vector *vct, char to_replace, char by)
{
	size_t		i;

	if (vct == NULL || vct->str == NULL)
		return ;
	i = 0;
	while (i < vct->len)
	{
		if (vct->str[i] == to_replace)
			vct->str[i] = by;
		i++;
	}
}
