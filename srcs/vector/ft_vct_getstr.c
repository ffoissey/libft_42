/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_getstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 08:50:58 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/01 15:37:43 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

char	*vct_getstr(t_vector *vct)
{
	if (vct == NULL)
		return (NULL);
	return (vct->str);
}
