/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_extend.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 12:00:30 by ffoissey          #+#    #+#             */
/*   Updated: 2020/03/11 17:37:19 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_fillcstr(const char *s, char **out, int null)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp_out;

	tmp_out = *out;
	if (!(tmp = ft_strchr(s, '%')))
	{
		*out = ft_strjoin_hub(*out, s, null, 1);
		ft_strdel(&tmp_out);
		return (NULL);
	}
	tmp2 = ft_strsub(s, 0, tmp - s);
	*out = ft_strjoin_hub(*out, tmp2, null, 1);
	ft_strdel(&tmp_out);
	ft_strdel(&tmp2);
	return (tmp + 1);
}

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

char	*ft_nb(va_list *args, char *format, t_flag *flag)
{
	if (*format == 'd' || *format == 'D' || *format == 'i' || *format == 'p')
		return (ft_hub_conversion_nb(va_arg(*args, long), flag, *format));
	return (ft_conversion_u(va_arg(*args, unsigned long), flag, *format));
}
