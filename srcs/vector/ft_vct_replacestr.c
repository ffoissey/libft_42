/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_replacestr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 12:11:24 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/01 15:20:45 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

static int	replace_string(t_vector *vct, char *str, char *to_replace, char *by)
{
	size_t		offset;
	size_t		len_replace;
	size_t		len;
	size_t		i;
	int			ret;

	i = 0;
	offset = 0;
	ret = SUCCESS;
	len_replace = ft_strlen(to_replace);
	len = vct->len;
	vct_clear(vct);
	while (i + offset <= len && ret == SUCCESS)
	{
		if (ft_strncmp(str + i + offset, to_replace, len_replace) == FALSE)
		{
			ret = vct_addstr(vct, by);
			offset += len_replace - 1;
		}
		else if (vct_add(vct, str[i + offset]) == FAILURE)
			ret = FAILURE;
		i++;
	}
	return (ret);
}

int			vct_replacestr(t_vector *vct, char *to_replace, char *by)
{
	char		*str;
	int			ret;

	if (vct == NULL || vct->str == NULL || to_replace == NULL || by == NULL)
		return (SUCCESS);
	if (ft_strcmp(to_replace, by) == FALSE || *to_replace == '\0')
		return (SUCCESS);
	str = vct_dupstr(vct);
	ret = replace_string(vct, str, to_replace, by);
	ft_strdel(&str);
	return (ret);
}
