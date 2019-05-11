/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:26:14 by ffoissey          #+#    #+#             */
/*   Updated: 2018/11/12 12:12:36 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	c_new;
	unsigned char	*ptr_tmp;

	ptr_tmp = (unsigned char *)b;
	c_new = (unsigned char)c;
	while (len-- > 0)
		*ptr_tmp++ = c_new;
	return (b);
}
