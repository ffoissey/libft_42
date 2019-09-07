/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:33:24 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/07 23:30:52 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long int	ft_u_conversion(unsigned long long int nb,
								t_flag *flag)
{
	if (flag->h)
		nb = (unsigned short int)(nb);
	else if (flag->hh)
		nb = (unsigned char)(nb);
	else if (flag->l_low)
		nb = (unsigned long int)(nb);
	else if (flag->ll)
		nb = (unsigned long long int)(nb);
	else
		nb = (unsigned int)(nb);
	return (nb);
}

static t_vector		*ft_set_ustring(uint64_t nb, t_option *option)
{
	t_vector	*vct;
	char		*s;
	int			base;

	base = 10;
	if ((option->flag & CONV_B) || (option->flag & CONV_B_MAJ))
		base = 2;
	else if ((option->flag & CONV_O) || (option->flag & CONV_O_MAJ))
		base = 8;
	else if ((option->flag & CONV_X) || (option->flag & CONV_X_MAJ))
		base = 16;
	s = ft_itoa_base_lu(nb, base);

	//////
	if (flag->sharp && (c == 'x' || c == 'X') && nb)
		flag->field -= 2;
	else if (flag->sharp && ft_strcmp(s, "0") && c == 'o')
		ft_join_free(&s, "0", 0, 0);
	else if (flag->sharp && c != 'b' && c != 'B')
		flag->sharp = 0;
	if (c == 'x')
		s = ft_strlowcase(s);
	flag->precision -= ft_strlen(s);
	flag->precision < 0 ? flag->precision = 0 : flag->precision;
	flag->field -= flag->precision + ft_strlen(s) + flag->space;
	return (s);
}

static char						*ft_binary_format(char *s)
{
	char	*new;
	int		i;
	int		j;
	int		count;

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
}

t_vector				*pboux_conv(va_list *arg, t_option *option)
{
	t_vector	*vct;
	uint64_t	nb;
	char		filler;

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
	nb = va_arg(*arg, unsigned long long);
	vct = set_u_string(nb, option);
	vct_fill(vct, '0', option->precision, PUSH);
	filler = (option->flag & FLAG_ZERO) ? '0' : ' ';
	vct_fill(vct, filler, option->field, option->flag & FLAG_MIN ? ADD : PUSH);
	if (option->flag & FLAG_SPACE)
		vct_push(vct, ' ');
	return (vct);	
}
