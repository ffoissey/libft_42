/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:26:48 by ffoissey          #+#    #+#             */
/*   Updated: 2020/04/22 17:12:50 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_output.h"

int	ft_putendl_fd(char const *s, int fd)
{
	if (!s)
		return (FAILURE);
	if (write(fd, s, ft_strlen(s)) == FAILURE)
		return (FAILURE);
	return ((int)write(fd, "\n", 1));
}
