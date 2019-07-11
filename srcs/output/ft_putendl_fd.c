/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:26:48 by ffoissey          #+#    #+#             */
/*   Updated: 2018/11/19 18:06:38 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_output.h"

int	ft_putendl_fd(char const *s, int fd)
{
	if (!s)
		return (0);
	write(fd, s, ft_strlen(s));
	return (write(fd, "\n", 1));
}
