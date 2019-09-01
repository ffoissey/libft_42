/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_joinfree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 09:23:38 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/01 09:26:48 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector	*vct_joinfree(t_vector **vct1, t_vector **vct2, int flag)
{
	t_vector	*new_vct;

	new_vct = vct_join(*vct1, *vct2);
	if (flag & FIRST)
		vct_del(vct1);
	if (flag & SECOND)
		vct_del(vct2);
	return (new_vct);
}
