/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_oth.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:06:34 by ffoissey          #+#    #+#             */
/*   Updated: 2019/01/28 16:51:11 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_fill_string(char **s, t_flag *flag, char c)
{
	int		tmp;

	tmp = 0;
	if (flag->precision >= 0)
	{
		if (flag->zero && c != 'o')
			tmp = flag->field;
		ft_filler(s, ft_strnew_c(flag->precision, '0'), 1, flag->null);
	}
	if (flag->field > 0 && flag->zero)
		ft_filler(s, ft_strnew_c(flag->field, '0'), 0, flag->null);
	if (c == 'p' || ((c == 'X' || c == 'x') && flag->sharp))
		ft_join_free(s, c == 'X' ? "0X" : "0x", 0, 0);
	if (flag->neg)
		ft_join_free(s, "-", 0, 0);
	else if (flag->plus)
		ft_join_free(s, "+", 0, 0);
	else if (flag->space)
		ft_join_free(s, " ", 0, flag->null);
	if (tmp > 0 && !flag->zero)
		ft_filler(s, ft_strnew_c(tmp, ' '), 0, flag->null);
}

char		*ft_conversion_char(int c, t_flag *flag)
{
	char	*s;

	s = NULL;
	if ((unsigned char)c == 0)
		flag->null++;
	flag->field--;
	if (flag->field < 0)
		flag->field = 0;
	s = ft_strnew_c((size_t)flag->field + 1, flag->zero ? '0' : ' ');
	if ((flag->min || flag->field <= 0))
		s[0] = (unsigned char)c;
	else if (flag->field > 0)
		s[flag->field] = (unsigned char)c;
	return (s);
}

char		*ft_conversion_str(const char *src, t_flag *flag)
{
	char	*s;

	s = NULL;
	if (!src && (flag->precision > 5 || flag->precision == 0) && !flag->dot)
		s = ft_strdup("(null)");
	else if (!src && flag->precision)
		s = ft_strndup("(null)", flag->precision);
	else if (flag->dot)
	{
		if (flag->precision > 0)
			s = ft_strndup(src, flag->precision);
	}
	else
		s = ft_strdup(src);
	flag->field = s ? (int)(flag->field - (ft_strlen(s))) : flag->field;
	if (flag->field > 0)
		ft_filler(&s, ft_strnew_c(flag->field, flag->zero && !flag->min ? '0'
		: ' '), flag->min, 0);
	return (s);
}

char		*ft_conversion_double(long double nb, t_flag *flag, char c)
{
	char	*s;
	int		len;

	s = ft_dtoa(&nb, flag->dot ? flag->precision : 6);
	ft_nan_inf(s, flag);
	ft_double_flag_neg(&s, flag);
	len = ft_strlen(s);
	if (flag->dot && !flag->precision && flag->sharp && s[len - 1] != '.')
		ft_join_free(&s, ".", 1, 0);
	if (s[len - 1] == '.' && !flag->sharp)
		s[len - 1] = '\0';
	if (flag->plus || flag->neg)
		flag->space = 0;
	if (c == 'F' && s
		&& (*s == 'n' || (*s == 'i' || (flag->neg && *(s + 1) == 'i'))))
		ft_strupcase(s);
	flag->precision -= len;
	flag->precision < 0 ? flag->precision = 0 : flag->precision;
	flag->field -= flag->precision + ft_strlen(s)
				+ flag->space + flag->plus + flag->neg;
	ft_fill_string(&s, flag, c);
	if (flag->field >= 0 && !flag->zero)
		ft_filler(&s, ft_strnew_c(flag->field, ' '), flag->min, flag->null);
	return (s);
}
