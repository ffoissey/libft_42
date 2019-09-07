/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_oth.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:06:34 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/07 23:20:24 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vector		*c_conv(va_list *arg, t_option *option)
{
	t_vector	*vct;
	char		*s;

	vct = vct_new(0);
	if (option->flag & FLAG_MIN)
		option->flag &= ~ FLAG_ZERO;
	if (option->flag & CONV_C_MAJ)
	{
		s = NULL; 
		ft_conversion_lchar(va_arg(*arg, wint_t), &s);
		vct_addstr(vct, s);
		ft_strdel(&s);
	}
	else if (option->flag & CONV_C)
		vct_add(vct, (char)va_arg(*arg, int));
	else
		vct_add(vct, (char)(option->flag >> CHAR_ERR_SHIFT));
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

	s = NULL;
	if (option->flag & CONV_S_MAJ)
		ft_conversion_lstr(va_arg(*arg, wchar_t *), option, &s);
	else
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
//	ft_fill_string(&s, flag, c);
	if (flag->field >= 0 && !flag->zero)
		ft_filler(&s, ft_strnew_c(flag->field, ' '), flag->min, flag->null);
	return (s);
}
