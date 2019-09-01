/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_replacestr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 12:11:24 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/01 13:06:54 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

static int	replace_string(t_vector *vct, char *str, char *to_replace, char *by)
{
	size_t		offset;
	size_t		len;
	size_t		i;
	int			ret;

	i = 0;
	offset = 0;
	ret = SUCCESS;
	len = ft_strlen(to_replace);
	while (i + offset < vct->len && ret == SUCCESS)
	{
		if (ft_strncmp(str, to_replace, len) == FALSE)
		{
			if (vct_addstr(vct, by) == FAILURE)
				ret = FAILURE;
			offset += len;
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
	str = vct_dupstr(vct);
	ret = replace_string(vct, str, to_replace, by);
	ft_strdel(&str);
	return (ret);
}
