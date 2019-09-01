/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_dupstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 08:52:07 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/01 13:02:47 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

char	*vct_dupstr(t_vector *vct)
{
	char	*s;
	size_t	i;

	if (vct == NULL)
		return (0);
	s = ft_strnew(vct->len + 1);
	i = 0;
	while (i < vct->len)
	{
		s[i] = vct->str[i];
		i++;
	}
	return (s);
}
