/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:34:58 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/13 15:39:42 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

ssize_t		vct_str(t_vector *vct, char *str)
{
	ssize_t index;
	size_t	len;

	if (vct == NULL || str == NULL)
		return (FAILURE);
	index = 0;
	len = ft_strlen(str);
	while ((size_t)index < vct->len)
	{
		if (ft_strncmp(vct->str + index, str, len) == FALSE)
			return (index);
		index++;
	}
	return (FAILURE);
}
