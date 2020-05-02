/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:19:47 by ffoissey          #+#    #+#             */
/*   Updated: 2020/04/22 17:55:16 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_prio(t_flag *flag, char c)
{
	if (c == 'j' || c == 'z')
		flag->ll = 1;
	if (flag->ll || flag->l_up)
	{
		flag->l_low = 0;
		flag->h = 0;
		flag->hh = 0;
	}
	else if (flag->l_low)
	{
		flag->h = 0;
		flag->hh = 0;
	}
	else if (flag->h)
		flag->hh = 0;
	if (flag->min)
		flag->zero = 0;
}

static char		*ft_set_flag_extend(char *s, t_flag *flag, char *tmp)
{
	ft_prio(flag, 0);
	if (*s == '%')
		return (ft_error_flag(s, flag));
	if (*s == 'Z' || *s == 'R')
	{
		tmp = ft_strndup(s, 1);
		flag->precision = 1;
		flag->str = ft_conversion_str(tmp, flag);
		ft_strdel(&tmp);
		return (*s ? s : NULL);
	}
	if ((*s && ((!*(s + 1) || *(s + 1) == '%') || !ft_strchr(s, '%')))
		&& (!ft_ok_conv(*s) && *s != '%' && *s))
	{
		ft_strdel(&flag->str);
		flag->str = ft_strcdup(s, '%');
		if (!ft_strchr(s, '%') && *s)
			while (*(s + 1))
				s++;
	}
	return (*s ? s : NULL);
}

char			*ft_set_all_flags(char *s, t_flag *flag)
{
	char	*tmp;

	tmp = s;
	flag->percent = 0;
	while (!ft_ok_conv(*s) && *s != '%' && *s)
	{
		if (*s == '#' || *s == '0' || *s == '-' || *s == '+' || *s == ' ')
			ft_set_attribute_flags(&s, flag);
		else if (*s == 'l' || *s == 'L' || *s == 'h')
			ft_set_length_flags(&s, flag);
		else if (*s == 'j' || *s == 'z')
			ft_prio(flag, *s);
		else if (*s == '*')
			ft_set_wildcard(flag);
		else if (*s == '.')
			ft_set_precision(&s, flag);
		else if (*s >= '0' && *s <= '9')
			ft_set_min_field_size(&s, flag);
		else if (!ft_check_flag(flag) && flag->space && *s != '%')
			return (ft_bad_flag(s, flag));
		else
			break ;
		s++;
	}
	return (ft_set_flag_extend(s, flag, tmp));
}
