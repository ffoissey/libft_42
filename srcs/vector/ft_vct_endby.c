/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_endby.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:41:49 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/13 15:45:11 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_endby(t_vector *vct, char *str)
{
	size_t	len;

	if (vct == NULL || str == NULL)
		return (FALSE);
	len = ft_strlen(str);
	if (len > vct->len || len == 0)
		return (FALSE);
	while (len--)
	{
		if (vct->str[len] != str[len])
			return (FALSE);
	}
	return (TRUE);
}
