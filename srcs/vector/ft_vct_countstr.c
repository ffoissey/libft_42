/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_countstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:49:23 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/13 15:50:55 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

size_t		vct_countstr(t_vector *vct, char *str)
{
	size_t index;
	size_t count;
	size_t	len;

	if (vct == NULL || str == NULL)
		return (FAILURE);
	index = 0;
	count = 0;
	len = ft_strlen(str);
	while (index < vct->len)
	{
		if (ft_strncmp(vct->str + index, str, len) == FALSE)
			count++;
		index++;
	}
	return (count);
}
