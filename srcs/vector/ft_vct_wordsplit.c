/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_wordsplit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:31:56 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/13 17:43:25 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

static size_t	get_offset(t_vector *init, char *str, size_t index, size_t len)
{
	size_t		offset;

	offset = 0;
	while (index + offset < init->len)
	{
		if (ft_strncmp(str, init->str + index + offset, len) == FALSE)
			break ;
		offset++;
	}
	return (offset);
}

t_vector		*vct_wordsplit(t_vector *vct, char *str)
{
	static t_vector *init = NULL;
	static size_t	index = 0;
	t_vector		*new_vct;
	size_t			offset;
	size_t			len;

	if (vct != init && vct != NULL)
	{
		init = vct;
		index = 0;
	}
	if (init == NULL || index >= init->len || str == NULL || init->str == NULL
		|| *str == '\0')
	{
		init = NULL;
		index = 0;
		return (NULL);
	}
	len = ft_strlen(str);
	offset = get_offset(init, str, index, len);
	new_vct = offset == 0 ? vct_newstr("\0")
			: vct_sub(init, index, index + offset);
	index += offset + len;
	return (new_vct);
}
