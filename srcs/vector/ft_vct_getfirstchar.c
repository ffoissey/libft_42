/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_getfirstchar.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:37:04 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/13 14:43:17 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

char	vct_getfirstchar(t_vector *vct)
{
	if (vct == NULL || vct->str == NULL || vct->len == 0)
		return ('\0');
	return (vct->str[0]);
}
