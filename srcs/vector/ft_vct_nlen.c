/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_nlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:22:55 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/13 14:25:49 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

size_t	vct_nlen(t_vector *vct, size_t n)
{
	if (vct == NULL)
		return (0);
	if (n > vct->len)
		n = vct->len;
	return (n);
}
