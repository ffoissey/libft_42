/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_trim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:50:22 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/13 16:58:07 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_trim(t_vector *vct, char *str)
{
	t_vector	*new_vct;
	size_t		i;
	size_t		j;

	if (vct == NULL || str == NULL || vct->str == NULL)
		return (FAILURE);
	new_vct = vct_new(vct->size);
	i = 0;
	j = 0;
	while (i < vct->len)
	{
		if (ft_strchr(str, vct->str[i]) == FALSE)
			new_vct->str[j++] = vct->str[i];
		i++;
	}
	new_vct->len = j;
	vct_clear(vct);
	vct_cpy(vct, new_vct);
	vct_del(&new_vct);
	return (SUCCESS);
}
