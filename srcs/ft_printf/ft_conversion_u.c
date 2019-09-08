/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:33:24 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/08 22:01:52 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uint64_t	apply_mod(uint64_t nb, uint64_t flag)
{
	if (flag & MOD_HH)
		nb = (uint8_t)(nb);
	else if (flag & MOD_H)
		nb = (uint16_t)(nb);
	else if ((flag & MOD_LL) == FALSE)
		nb = (uint32_t)(nb);
	return (nb);
}

static t_vector		*set_ustring(uint64_t nb, t_option *option)
{
	t_vector	*vct;
	char		*s;
	size_t		len;
	int			base;

	base = 10;
	if ((option->flag & CONV_B) || (option->flag & CONV_B_MAJ))
		base = 2;
	else if ((option->flag & CONV_O) || (option->flag & CONV_O_MAJ))
		base = 8;
	else if ((option->flag & CONV_X) || (option->flag & CONV_X_MAJ)
			|| (option->flag & CONV_P))
		base = 16;
	s = ft_itoa_base_lu(nb, base);
	vct = vct_newstr(s);
	ft_strdel(&s);
	if ((option->flag & FLAG_HASH) || (option->flag & CONV_P))
	{
		if ((option->flag & CONV_X) || (option->flag & CONV_X_MAJ)
			|| (option->flag & CONV_P))
			option->field = option->field > 1 ? option->field - 2 : 0;
		else if (nb == 0
				&& ((option->flag & CONV_O) || (option->flag & CONV_O_MAJ)))
			vct_add(vct, '0');
		else if ((option->flag & CONV_B) == FALSE
				&& (option->flag & CONV_B_MAJ) == FALSE)
			option->flag &= ~(FLAG_HASH);
	}
	len = vct_len(vct);
	option->precision -= len < option->precision ? len : option->precision;
	option->field -= (len + option->precision) < option->field ?
			len + option->precision : option->field;
	return (vct);
}
/*
static char						*ft_binary_format(char *s)
{
	char		*new;
	int			i;
	int			j;
	int			count;

	i = -1;
	count = 0;
	while (s[++i])
		if (s[i] == '0' || s[i] == '1')
			count++;
	count = !(count % 8) && count ? count / 8 - 1 : count / 8;
	new = ft_strnew(ft_strlen(s) + count);
	j = ft_strlen(s) - 1;
	i = ft_strlen(s) + count - 1;
	count = 0;
	while (j >= 0 && s[j] != '0' && s[j] != '1')
		new[i--] = s[j--];
	while (j >= 0 && i >= 0)
	{
		if (!(count++ % 8) && count != 1 && (s[j] == '0' || s[j] == '1'))
			new[i--] = ' ';
		new[i--] = s[j--];
	}
	ft_strdel(&s);
	return (new);
}*/

t_vector				*pboux_conv(va_list *arg, t_option *option)
{
	t_vector			*vct;
	uint64_t			nb;
	char				filler;

	option->flag &= ~FLAG_PLUS;
	option->flag &= ~FLAG_SPACE;
	if ((option->flag & FLAG_DOT) || (option->flag & FLAG_MIN))
		option->flag &= ~FLAG_ZERO;
	//if ((option->flag & FLAG_SPACE) && option->field > 0)
	//	option->field--;
	if ((option->flag & CONV_U_MAJ) || (option->flag & CONV_O_MAJ))
	{
		option->flag &= ~(ALL_MOD);
		option->flag |= MOD_LL;
	}
	nb = apply_mod(va_arg(*arg, uint64_t), option->flag);
	vct = set_ustring(nb, option);
	vct_fill(vct, '0', option->precision, PUSH);
	filler = (option->flag & FLAG_ZERO) ? '0' : ' ';
	if (filler == '0')
		vct_fill(vct, filler, option->field, option->flag & FLAG_MIN ? ADD : PUSH);
	if (((option->flag & FLAG_HASH) && ((option->flag & CONV_X)
			|| (option->flag & CONV_X_MAJ)))
			|| (option->flag & CONV_P))
			vct_pushstr(vct, "0X");
	if (filler == ' ')
		vct_fill(vct, filler, option->field, option->flag & FLAG_MIN ? ADD : PUSH);
	if ((option->flag & CONV_X) || (option->flag & CONV_P))
		vct_apply(vct, ft_strlowcase);
	return (vct);	
}
