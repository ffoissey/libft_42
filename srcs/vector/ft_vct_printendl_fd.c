/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_printendl_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:32:01 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/13 14:32:33 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_printendl_fd(t_vector *vct, int fd)
{
	write(fd, vct->str, vct->len);
	return (write(fd, "\n", 1));
}
