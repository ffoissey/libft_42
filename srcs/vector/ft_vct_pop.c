/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_pop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 22:18:21 by ffoissey          #+#    #+#             */
/*   Updated: 2019/08/31 22:24:22 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_pop(t_vector *vector)
{
	if (vct->len == 0)
		return (SUCCESS);
	ft_memmove(vct->str, vct->str + 1, vct->len);
	vct->len--;
	return (SUCCESS);
}
