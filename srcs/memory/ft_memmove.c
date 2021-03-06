/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:35:45 by ffoissey          #+#    #+#             */
/*   Updated: 2020/04/22 17:10:24 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_cp;
	const unsigned char	*src_cp;

	dst_cp = (unsigned char *)dst;
	src_cp = (const unsigned char *)src;
	if (dst < src)
	{
		while (len--)
			*dst_cp++ = *src_cp++;
	}
	else
	{
		while (len--)
			*(dst_cp + len) = *(src_cp + len);
	}
	return (dst);
}
