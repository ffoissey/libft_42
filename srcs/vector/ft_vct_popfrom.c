/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_popfrom.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 08:36:52 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/01 13:04:39 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_popfrom(t_vector *vct, size_t index)
{
	size_t	i;

	if (vct == NULL)
		return (FAILURE);
	if (vct->len == 0)
		return (SUCCESS);
	i = 0;
	while (i < vct->len)
		vct->str[i++] = vct->str[index++];
	if (i > 0)
		vct->str[i - 1] = '\0';
	vct->len -= index;;
	return (SUCCESS);
}
