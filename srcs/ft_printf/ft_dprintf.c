/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 11:27:33 by ffoissey          #+#    #+#             */
/*   Updated: 2019/01/28 13:06:23 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_dprintf(int fd, const char *format, ...)
{
	char	*out;
	int		len;
	va_list	args;
	t_flag	flag;

	flag.null = 0;
	if (!format || !*format)
		return (0);
	out = NULL;
	va_start(args, format);
	len = ft_loop_args((char *)format, &args, &out, &flag);
	va_end(args);
	ft_strdel(&flag.str);
	if (len != -1)
	{
		len = ft_strlen_null(out, flag.null);
		write(fd, out, len);
	}
	ft_strdel(&out);
	return (len);
}
