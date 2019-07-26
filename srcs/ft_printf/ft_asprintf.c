/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 11:27:33 by ffoissey          #+#    #+#             */
/*   Updated: 2019/07/26 11:14:29 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_asprintf(const char *format, ...)
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
	len = ft_loop_args((char *)format, &args, &out, &flag);
	va_end(args);
	ft_strdel(&flag.str);
	if (len == -1)
	{
		ft_strdel(&out);
		return (NULL);
	}
	return (out);
}
