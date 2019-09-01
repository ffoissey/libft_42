/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_strcheck.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 12:41:15 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/01 13:07:33 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_strcheck(t_vector *vct, int (*f)(char *))
{
	if (vct == NULL || f == NULL)
		return (FAILURE);
	return (f(vct->str));
}
