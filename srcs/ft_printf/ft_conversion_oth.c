/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_oth.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:06:34 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/07 22:33:26 by ffoissey         ###   ########.fr       */
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

t_vector		*c_conv(va_list *arg, t_option *option)
{
	t_vector	*vct;
	char		c;

	vct = vct_new(0);
	c = (char)va_arg(*arg, int);
	vct_add(vct, c);
	if (option->field > 0)
		option->field--;
	vct_fill(vct, option->flag & FLAG_ZERO ? '0' : ' ', option->field,
			option->flag & FLAG_MIN ? ADD : PUSH);
	return (vct);
}

t_vector	*s_conv(va_list *arg, t_option *option)
{
	char		*s;
	t_vector	*vct;

	s = va_arg(*arg, char *);
	option->flag &=~ FLAG_SPACE;
	vct = vct_newstr(s == NULL ? "(null)" : s);
	vct_cutfrom(vct, option->precision);
	if (option->field > vct_len(vct))
		option->field -= vct_len(vct);
	else
		option->field = 0;
	vct_fill(vct, option->flag & FLAG_ZERO ? '0' : ' ', option->field,
			option->flag & FLAG_MIN ? ADD : PUSH);
	if (option->flag & FLAG_SPACE)
		vct_push(vct, ' ');
	return (vct);
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
