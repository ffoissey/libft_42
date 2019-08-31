/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:29:22 by ffoissey          #+#    #+#             */
/*   Updated: 2019/08/31 20:24:39 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dst_cp;
	const unsigned char	*src_cp;

	dst_cp = (unsigned char *)dst;
	src_cp = (const unsigned char *)src;
	while (n)
	{
		if ((*dst_cp++ = *src_cp++) == (unsigned char)c)
			return ((void *)(dst_cp));
		n--;
	}
	return (NULL);
}
