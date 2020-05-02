/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_extend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:19:32 by ffoissey          #+#    #+#             */
/*   Updated: 2020/04/22 17:44:11 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_init_flags(t_flag *flag)
{
	flag->sharp = 0;
	flag->zero = 0;
	flag->min = 0;
	flag->plus = 0;
	flag->l_low = 0;
	flag->l_up = 0;
	flag->ll = 0;
	flag->h = 0;
	flag->hh = 0;
	flag->dot = 0;
	flag->space = 0;
	flag->precision = 0;
	flag->field = 0;
	flag->neg = 0;
	flag->str = NULL;
	flag->wildcard = 0;
}

char		*ft_bad_flag(char *s, t_flag *flag)
{
	flag->str = ft_strcdup(s, '%');
	if (*(s + ft_strclen(s, '%')) == '%' && flag->str && *flag->str)
		flag->percent = 1;
	return (s + ft_strclen(s, '%'));
}

int			ft_check_flag(t_flag *flag)
{
	return (!flag->sharp && !flag->zero && !flag->min && !flag->plus
			&& !flag->l_low && !flag->l_up && !flag->ll && !flag->h && !flag->hh
			&& !flag->dot && !flag->precision && !flag->field);
}

char		*ft_error_flag(char *s, t_flag *flag)
{
	if (flag->min || flag->sharp)
		flag->zero = 0;
	if (flag->field || flag->zero || flag->dot || flag->sharp || flag->plus
		|| flag->space || (flag->space && *s && *(s + 1)) || flag->min)
	{
		if (flag->field > 1)
			ft_filler(&flag->str, ft_strnew_c((size_t)flag->field - 1,
				flag->zero ? '0' : ' '), 0, 0);
		ft_join_free(&flag->str, "%", flag->min ? 0 : 1, 0);
	}
	else
		flag->str = ft_strcdup(s, '%');
	return (s);
}
