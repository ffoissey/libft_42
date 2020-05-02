/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:27:05 by ffoissey          #+#    #+#             */
/*   Updated: 2020/04/22 16:11:32 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_output.h"

int		ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		if (n == -2147483648)
			return (ft_putstr_fd("-2147483648", fd));
		if (write(fd, "-", 1) == FAILURE)
			return (FAILURE);
		return (ft_putnbr_fd(-n, fd));
	}
	else if (n <= 9)
		return (ft_putchar_fd((char)(n + '0'), fd));
	else
	{
		if (ft_putnbr_fd(n / 10, fd) == FAILURE)
			return (FAILURE);
		return (ft_putnbr_fd(n % 10, fd));
	}
}
