/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:04:46 by ffoissey          #+#    #+#             */
/*   Updated: 2020/05/14 20:23:09 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

static size_t	til_next(t_vector *init, char *str, size_t index)
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

static ssize_t	get_offset(t_vector *init, char *str, size_t *index,
						uint8_t flag)
{
	size_t		offset;

	offset = 0;
	while (*index + offset < init->len
			&& ft_strchr(str, init->str[*index + offset]) != NULL)
	{
		offset++;
		if (flag & EACH_SEP)
			break ;
	}
	if (flag & NO_SEP)
		*index += offset;
	if (offset == 0 || (flag & NO_SEP))
		offset = til_next(init, str, *index);
	return (offset == 0 && (flag & NO_SEP) ? -1 : (ssize_t)offset);
}

t_vector		*vct_split(t_vector *vct, char *str, uint8_t flag)
{
	static t_vector *init = NULL;
	static size_t	index = 0;
	t_vector		*new_vct;
	ssize_t			offset;

	if ((vct != init && vct != NULL) || (flag & INIT))
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
	offset = get_offset(init, str, &index, flag);
	new_vct = NULL;
	if (offset == 0)
		new_vct = vct_newstr("");
	else if (offset != -1)
		new_vct = vct_sub(init, index, index + (size_t)offset);
	index += (size_t)offset;
	return (new_vct);
}
