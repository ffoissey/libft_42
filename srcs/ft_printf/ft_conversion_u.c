/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:33:24 by ffoissey          #+#    #+#             */
/*   Updated: 2020/04/22 17:38:01 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long	ft_u_conversion(unsigned long nb,
								t_flag *flag)
{
	if (flag->h)
		nb = (unsigned short)(nb);
	else if (flag->hh)
		nb = (unsigned char)(nb);
	else if (flag->l_low)
		nb = (unsigned long)(nb);
	else if (flag->ll)
		nb = (unsigned long)(nb);
	else
		nb = (unsigned int)(nb);
	return (nb);
}

static char				*ft_set_ustring(unsigned long nb,
								t_flag *flag, char c)
{
	char			*s;
	unsigned int	base;

	base = 10;
	if (c == 'b' || c == 'B')
		base = 2;
	else if (c == 'o')
		base = 8;
	else if (c == 'x' || c == 'X')
		base = 16;
	s = ft_itoa_base_lu(nb, base);
	if (flag->sharp && (c == 'x' || c == 'X') && nb)
		flag->field -= 2;
	else if (flag->sharp && ft_strcmp(s, "0") && c == 'o')
		ft_join_free(&s, "0", 0, 0);
	else if (flag->sharp && c != 'b' && c != 'B')
		flag->sharp = 0;
	if (c == 'x')
		s = ft_strlowcase(s);
	flag->precision -= (int)ft_strlen(s);
	flag->precision < 0 ? flag->precision = 0 : flag->precision;
	flag->field -= flag->precision + (int)ft_strlen(s) + flag->space;
	return (s);
}

static void				ft_major(char *c, t_flag *flag)
{
	if (*c == 'O')
	{
		flag->h = 0;
		flag->hh = 0;
		flag->l_low = 0;
		flag->ll = 1;
		*c = 'o';
	}
	if (*c == 'U')
	{
		flag->h = 0;
		flag->hh = 0;
		flag->l_low = 0;
		flag->ll = 1;
		*c = 'u';
	}
	if (flag->dot && !flag->wildcard)
		flag->zero = 0;
	flag->plus = 0;
	flag->neg = 0;
	flag->space = 0;
}

static char				*ft_binary_format(char *s)
{
	char	*new;
	int		i;
	int		j;
	size_t	count;

	i = -1;
	count = 0;
	while (s[++i])
		if (s[i] == '0' || s[i] == '1')
			count++;
	count = !(count % 8) && count != 0 ? count / 8 - 1 : count / 8;
	new = ft_strnew(ft_strlen(s) + count);
	j = (int)ft_strlen(s) - 1;
	i = (int)ft_strlen(s) + (int)count - 1;
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

char					*ft_conversion_u(unsigned long nb,
								t_flag *flag, char c)
{
	char	*s;

	ft_major(&c, flag);
	s = NULL;
	if (flag->sharp && c == 'o' && nb == 0)
	{
		s = ft_strdup("0");
		if (flag->dot && !flag->precision)
			flag->field--;
		flag->sharp = 0;
	}
	if (flag->dot && !flag->precision && nb == 0)
		flag->sharp = 0;
	else
		s = ft_set_ustring(ft_u_conversion(nb, flag), flag, c);
	ft_fill_string(&s, flag, c);
	if ((c == 'b' || c == 'B') && flag->sharp)
		s = ft_binary_format(s);
	if (flag->field > 0 && !flag->zero)
		ft_filler(&s, ft_strnew_c((size_t)flag->field, ' '),
				flag->min, flag->null);
	return (s);
}
