/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 08:59:31 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/01 09:06:08 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	vct_clear(t_vector *vct)
{
	size_t	i;

	if (vct == NULL || vct->str == NULL)
		return ;
	i = 0;
	while (i < vct->len)
		vct->str[i++] == '\0';
	vct->len = 0;
	vct->scale = VCT_DFL_SCALE;
}
