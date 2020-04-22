/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_printendl_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:32:01 by ffoissey          #+#    #+#             */
/*   Updated: 2020/04/22 17:14:52 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_printendl_fd(t_vector *vct, int fd)
{
	if (vct == NULL || vct->str == NULL)
		return (FAILURE);
	if (write(fd, vct->str, vct->len) == FAILURE)
		return (FAILURE);
	return ((int)write(fd, "\n", 1));
}
