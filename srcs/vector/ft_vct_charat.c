/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_charat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:44:08 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/01 18:04:51 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_charat(t_vector *vct, char c, size_t index)
{
	if (vct == NULL)
		return (FAILURE);
	if (index < vct->len)
		vct->str[index] = c;
	return (SUCCESS);
}
