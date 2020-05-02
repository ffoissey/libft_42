/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:26:08 by ffoissey          #+#    #+#             */
/*   Updated: 2020/04/22 17:09:30 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_cp;
	const unsigned char	*src_cp;

	dst_cp = (unsigned char *)dst;
	src_cp = (const unsigned char *)src;
	while (n-- > 0)
		*dst_cp++ = *src_cp++;
	return (dst);
}
