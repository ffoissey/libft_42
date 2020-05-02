/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:28:49 by ffoissey          #+#    #+#             */
/*   Updated: 2020/04/22 17:13:28 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_print(t_vector *vct)
{
	if (vct == NULL || vct->str == NULL)
		return (FAILURE);
	return ((int)write(STDOUT_FILENO, vct->str, vct->len));
}
