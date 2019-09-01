/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_popfrom.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 08:36:52 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/01 18:24:35 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_popfrom(t_vector *vct, size_t index)
{
	size_t	i;
	size_t	len;

	if (vct == NULL || index == 0)
		return (FAILURE);
	if (vct->len == 0)
		return (SUCCESS);
	if (index > vct->len)
		index = vct->len;
	i = 0;
	len = index;
	while (i < vct->len)
		vct->str[i++] = vct->str[index++];
	if (i > 0)
		vct->str[i - 1] = '\0';
	vct->len -= len;
	return (SUCCESS);
}
