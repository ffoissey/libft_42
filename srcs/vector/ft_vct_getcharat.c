/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_getcharat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:35:25 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/13 14:42:30 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

char	vct_getcharat(t_vector *vct, size_t index)
{
	if (vct == NULL || vct->str == NULL || index >= vct->len)
		return ('\0');
	return (vct->str[index]);
}
