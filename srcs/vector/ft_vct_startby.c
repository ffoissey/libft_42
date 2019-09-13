/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_startby.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:40:31 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/13 15:45:07 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_startby(t_vector *vct, char *str)
{
	size_t	len;

	if (vct == NULL || str == NULL)
		return (FALSE);
	len = ft_strlen(str);
	if (len > vct->len || len == 0)
		return (FALSE);
	if (ft_strncmp(vct->str, str, len) == FALSE)
		return (TRUE);
	return (FALSE);
}
