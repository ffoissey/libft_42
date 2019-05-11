/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasecmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:54:57 by ffoissey          #+#    #+#             */
/*   Updated: 2019/01/16 13:18:28 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include <string.h>

static unsigned int	ft_cmp_char(const char c1, const char c2)
{
	unsigned char c1_tmp;
	unsigned char c2_tmp;

	c1_tmp = (unsigned char)ft_toupper(c1);
	c2_tmp = (unsigned char)ft_toupper(c2);
	return ((int)(c1_tmp - c2_tmp));
}

int					ft_strcasecmp(const char *s1, const char *s2)
{
	size_t	i;
	int		ret;

	i = 0;
	while (s1[i] != '\0')
	{
		if ((ret = ft_cmp_char(s1[i], s2[i])))
			return (ret);
		i++;
	}
	return (0);
}
