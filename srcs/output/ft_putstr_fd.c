/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:27:21 by ffoissey          #+#    #+#             */
/*   Updated: 2020/04/22 17:12:03 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_output.h"

int		ft_putstr_fd(char const *s, int fd)
{
	if (!s)
		return (FAILURE);
	return ((int)write(fd, s, ft_strlen(s)));
}
