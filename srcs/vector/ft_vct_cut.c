/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_cut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 22:20:47 by ffoissey          #+#    #+#             */
/*   Updated: 2019/08/31 22:24:23 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_cut(t_vector *vector)
{
	if (vct->len == 0)
		return (SUCCESS);
	vct->str[vct->len - 1] = '\0';
	vct->len--;
	return (SUCCESS);
}
