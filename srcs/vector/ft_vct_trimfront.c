/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_trimfront.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:49:13 by ffoissey          #+#    #+#             */
/*   Updated: 2020/03/11 19:50:56 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_trimfront(t_vector *vct, char *str)
{
	size_t		i;

	i = 0;
	if (vct == NULL || str == NULL || vct->str == NULL)
		return (FAILURE);
	while (i < vct->len && ft_strchr(str, vct->str[i]) != NULL)
		i++;
	vct_popfrom(vct, i);
	return (SUCCESS);
}
