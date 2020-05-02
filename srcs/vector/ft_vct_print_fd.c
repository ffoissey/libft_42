/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_print_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:27:06 by ffoissey          #+#    #+#             */
/*   Updated: 2020/04/22 17:13:50 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_print_fd(t_vector *vct, int fd)
{
	if (vct == NULL || vct->str == NULL)
		return (FAILURE);
	return ((int)write(fd, vct->str, vct->len));
}
