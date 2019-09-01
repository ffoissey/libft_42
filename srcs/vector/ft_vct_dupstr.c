/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_dupstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 08:52:07 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/01 08:52:53 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

char	*vct_dupstr(t_vector *vector)
{
	if (vct == NULL)
		return (0);
	return (ft_strdup(vct->str));
}
