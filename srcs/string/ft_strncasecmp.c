/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncasecmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:57:37 by ffoissey          #+#    #+#             */
/*   Updated: 2018/11/13 17:26:36 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static unsigned char	ft_cmp_char(const char c1, const char c2)
{
	unsigned char c1_tmp;
	unsigned char c2_tmp;

	c1_tmp = (unsigned char)ft_toupper(c1);
	c2_tmp = (unsigned char)ft_toupper(c2);
	return (c1_tmp == c2_tmp);
}

int						ft_strncasecmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (!ft_cmp_char(s1[i], s2[i]))
			return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
		i++;
	}
	return (0);
}
