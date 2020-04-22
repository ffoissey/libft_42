/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_printendl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:30:59 by ffoissey          #+#    #+#             */
/*   Updated: 2020/04/22 17:14:23 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_printendl(t_vector *vct)
{
	if (vct == NULL || vct->str == NULL)
		return (FAILURE);
	if (write(STDOUT_FILENO, vct->str, vct->len) == FAILURE)
		return (FAILURE);
	return ((int)write(STDOUT_FILENO, "\n", 1));
}
