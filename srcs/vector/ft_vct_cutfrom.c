/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_cutfrom.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 08:33:04 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/01 18:21:55 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_cutfrom(t_vector *vct, size_t index)
{
	size_t	len;

	if (vct == NULL)
		return (FAILURE);
	if (vct->len == 0)
		return (SUCCESS);
	if (index > vct->len)
		index = vct->len;
	len = vct->len - (vct->len - index);
	while (index < vct->len)
		vct->str[index++] = '\0';
	vct->len = len;
	return (SUCCESS);
}
