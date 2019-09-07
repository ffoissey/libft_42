/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_extend.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 12:00:30 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/07 23:23:08 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	ft_wildcard(va_list *args, t_flag *flag)
{
	int		tmp_field;

	if (flag->wildcard)
	{
		if (!flag->dot && (tmp_field = va_arg(*args, int)))
		{
			flag->wildcard--;
			if (!flag->field && (flag->field = tmp_field) < 0)
			{
				flag->min = 1;
				flag->field = -flag->field;
			}
		}
		else if (flag->wildcard > 1)
			va_arg(*args, int);
		if (flag->wildcard && flag->dot)
		{
			if ((tmp_field = va_arg(*args, int)) < 0)
				flag->dot = 0;
			else
				flag->precision = tmp_field;
		}
	}
}

double	ft_double_select(va_list *args, t_flag *flag)
{
	long double	nb;
	double		nb2;

	if (flag->l_up)
		nb = va_arg(*args, long double);
	else
	{
		nb2 = va_arg(*args, double);
		nb = (long double)nb2;
	}
	return (nb);
}
