/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:12:19 by ffoissey          #+#    #+#             */
/*   Updated: 2018/11/07 17:18:20 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp_s;
	size_t			i;
	unsigned char	c_cp;

	i = 0;
	tmp_s = (unsigned char *)s;
	c_cp = (unsigned char)c;
	while (i < n)
	{
		if (c_cp == tmp_s[i])
			return ((void *)(tmp_s + i));
		i++;
	}
	return (NULL);
}
