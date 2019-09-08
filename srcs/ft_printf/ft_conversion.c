/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 12:47:12 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/08 22:01:53 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int64_t	apply_mod(int64_t nb, uint64_t flag)
{
	if (flag & MOD_HH)
		nb = (int8_t)(nb);
	else if (flag & MOD_H)
		nb = (int16_t)(nb);
	else if ((flag & MOD_LL) == FALSE)
		nb = (int32_t)(nb);
	return (nb);
}

static t_vector	*set_string(int64_t nb, t_option *option)
{
	t_vector	*vct;
	char		*tmp_str;
	size_t		len;

	tmp_str = ft_itoa_base_l(nb, 10);
	vct = vct_newstr(tmp_str);
	ft_strdel(&tmp_str);
	len = vct_len(vct);
	option->precision -= len < option->precision ? len : option->precision;
	option->field -= (len + option->precision) < option->field ?
			len + option->precision : option->field;
	return (vct);
}

t_vector		*di_conv(va_list *arg, t_option *option)
{
	t_vector	*vct;
	int64_t		nb;
	char		filler;
	uint8_t		neg;

	if (option->flag & FLAG_PLUS)
		option->flag &= ~FLAG_SPACE;
	if ((option->flag & FLAG_DOT) || (option->flag & FLAG_MIN))
		option->flag &= ~FLAG_ZERO;
	if ((option->flag & FLAG_SPACE) && option->field > 0)
		option->field--;
	if (option->flag & CONV_D_MAJ)
	{
		option->flag &= ~(ALL_MOD);
		option->flag |= MOD_LL;
	}
	neg = FALSE;
	nb = apply_mod(va_arg(*arg, int64_t), option->flag);
	if (nb < 0)
	{
		neg = TRUE;
		nb = -nb;
		if (option->field > 0)
			option->field--;
	}
	vct = set_string(nb, option);
	vct_fill(vct, '0', option->precision, PUSH);
	filler = (option->flag & FLAG_ZERO) ? '0' : ' ';
	if (filler == '0')
		vct_fill(vct, filler, option->field, option->flag & FLAG_MIN ? ADD : PUSH);
	if (neg == TRUE)
		vct_push(vct, '-');
	if (filler == ' ')
		vct_fill(vct, filler, option->field, option->flag & FLAG_MIN ? ADD : PUSH);
	if (option->flag & FLAG_SPACE)
		vct_push(vct, ' ');
	if ((option->flag & FLAG_PLUS) && neg == FALSE)
		vct_push(vct, '+');
	return (vct);
}
