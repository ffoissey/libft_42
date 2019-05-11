/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 12:47:12 by ffoissey          #+#    #+#             */
/*   Updated: 2019/01/28 13:00:57 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long int	ft_di_conversion(long long int nb, t_flag *flag)
{
	if (flag->h)
		nb = (short int)(nb);
	else if (flag->hh)
		nb = (char)(nb);
	else if (flag->l_low)
		nb = (long int)(nb);
	else if (!flag->ll)
		nb = (int)(nb);
	return (nb);
}

static char				*ft_set_string(long long int nb,
						t_flag *flag, char c)
{
	char *s;

	if (c == 'p')
	{
		flag->field -= 2;
		s = ft_strlowcase(ft_itoa_base_lu((unsigned long)nb, 16));
	}
	else if (nb < MIN_LONG)
		s = ft_strdup(MIN_LONG_STR);
	else
		s = ft_itoa_base_l(nb, 10);
	flag->precision -= ft_strlen(s);
	flag->precision < 0 ? flag->precision = 0 : flag->precision;
	flag->field -= flag->precision + ft_strlen(s)
				+ flag->neg + flag->plus + flag->space;
	return (s);
}

static char				*ft_split_conversion_nb(long long int nb,
						t_flag *flag, char c)
{
	nb = ft_di_conversion(nb, flag);
	if (nb < 0)
	{
		flag->neg = 1;
		flag->space = 0;
		flag->plus = 0;
		nb *= -1;
	}
	return (ft_set_string(nb, flag, c));
}

static void				ft_up_d(char *c, t_flag *flag)
{
	if (*c == 'D')
	{
		flag->h = 0;
		flag->hh = 0;
		flag->l_low = 0;
		flag->ll = 1;
		*c = 'd';
	}
	flag->sharp = 0;
	if (*c == 'p')
		flag->plus = 0;
	if (flag->dot && !flag->wildcard)
		flag->zero = 0;
	if (flag->plus || *c == 'p')
		flag->space = 0;
}

char					*ft_hub_conversion_nb(long long int nb,
						t_flag *flag, char c)
{
	char	*s;

	ft_up_d(&c, flag);
	if (flag->dot && !flag->precision && nb == 0)
		s = NULL;
	else if (c != 'p')
		s = ft_split_conversion_nb(nb, flag, c);
	else
		s = ft_set_string(nb, flag, c);
	if (flag->plus && flag->neg)
		flag->space = 0;
	ft_fill_string(&s, flag, c);
	if (flag->field > 0 && !flag->zero)
		ft_filler(&s, ft_strnew_c(flag->field, ' '), flag->min, flag->null);
	return (s);
}
