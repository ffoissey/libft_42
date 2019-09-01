/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_apply.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 12:41:45 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/01 12:41:46 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	vct_apply(t_vector *vct, void (*f)(char *))
{
	if (vct == NULL || f == NULL)
		return ;
	f(vct->str);
}
