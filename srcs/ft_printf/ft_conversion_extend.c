/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_extend.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 16:20:39 by ffoissey          #+#    #+#             */
/*   Updated: 2019/01/28 16:26:29 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_nan_inf(char *s, t_flag *flag)
{
	if (!ft_strcasecmp(s, "inf") || !ft_strcasecmp(s, "nan")
		|| !ft_strcasecmp(s, "-inf"))
	{
		flag->precision = 0;
		flag->dot = 0;
		flag->space = 0;
		flag->plus = 0;
		flag->zero = 0;
	}
}

void	ft_double_flag_neg(char **s, t_flag *flag)
{
	if (ft_strcasecmp(*s, "-inf") && *s && s[0][0] == '-')
	{
		ft_dup(s, ft_strdup(*s + 1));
		flag->neg = 1;
		flag->plus = 0;
	}
}
