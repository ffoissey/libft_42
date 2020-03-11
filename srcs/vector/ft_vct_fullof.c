/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_fullof.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:30:46 by ffoissey          #+#    #+#             */
/*   Updated: 2020/03/11 19:34:06 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int				vct_fullof(t_vector *vct, char *charset)
{
	size_t	i;

	i = 0;
	if (vct == NULL || vct->str == NULL)
		return (FALSE);
	while (i < vct->len)
	{
		if (ft_strchr(charset, vct->str[i]) == NULL)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
