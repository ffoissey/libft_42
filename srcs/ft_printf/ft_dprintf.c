/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 11:27:33 by ffoissey          #+#    #+#             */
/*   Updated: 2020/04/22 17:59:09 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_dprintf(int fd, const char *format, ...)
{
	char	*out;
	int		len;
	va_list	args;
	t_flag	flag;

	ft_bzero(&flag, sizeof(t_flag));
	if (!format || !*format)
		return (0);
	out = NULL;
	va_start(args, format);
	len = ft_loop_args(format, &args, &out, &flag);
	va_end(args);
	ft_strdel(&flag.str);
	if (len != -1)
	{
		len = (int)ft_strlen_null(out, flag.null);
		if (write(fd, out, (size_t)len) == FAILURE)
			len = -1;
	}
	ft_strdel(&out);
	return (len);
}
