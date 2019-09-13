/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:04:46 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/13 17:43:10 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

static size_t	get_offset(t_vector *init, char *str, size_t index)
{
	size_t		offset;

	offset = 0;
	while (index + offset < init->len)
	{
		if (ft_strchr(str, init->str[index + offset]) != NULL)
			break ;
		offset++;
	}
	return (offset);
}

t_vector		*vct_split(t_vector *vct, char *str)
{
	static t_vector *init = NULL;
	static size_t	index = 0;
	t_vector		*new_vct;
	size_t			offset;

	if (vct != init && vct != NULL)
	{
		init = vct;
		index = 0;
	}
	if (init == NULL || index >= init->len || str == NULL || init->str == NULL)
	{
		init = NULL;
		index = 0;
		return (NULL);
	}
	offset = get_offset(init, str, index);
	new_vct = offset == 0 ? vct_newstr("\0")
					: vct_sub(init, index, index + offset);
	index += offset + 1;
	return (new_vct);
}
