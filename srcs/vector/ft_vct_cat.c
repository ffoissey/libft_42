/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_cat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 09:18:16 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/01 19:23:42 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_cat(t_vector *dest, t_vector *src)
{
	if (dest == NULL || src == NULL || dest->str == NULL || src->str == NULL)
		return (SUCCESS);
	return (vct_addstr(dest, src->str));
}
