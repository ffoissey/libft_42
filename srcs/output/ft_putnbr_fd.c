/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:27:05 by ffoissey          #+#    #+#             */
/*   Updated: 2018/11/19 18:07:19 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_output.h"

int		ft_putnbr_fd(int n, int fd)
{
	int		ret;

	if (n < 0)
	{
		if (n == -2147483648)
		{
			ret = ft_putstr_fd("-2147483648", fd);
			return (ret);
		}
		ret = write(fd, "-", 1);
		ret = ft_putnbr_fd(-n, fd);
	}
	else if (n <= 9)
		ret = ft_putchar_fd((char)(n + '0'), fd);
	else
	{
		ret = ft_putnbr_fd(n / 10, fd);
		ret = ft_putnbr_fd(n % 10, fd);
	}
	return (ret);
}
