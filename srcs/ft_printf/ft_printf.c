/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 11:27:33 by ffoissey          #+#    #+#             */
/*   Updated: 2019/01/28 13:06:23 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conversion_c_n_s(va_list *args, char *s, t_flag *flag,
			char **new)
{
	if (*s == 'c' || *s == 'C')
	{
		if (*s == 'C' || flag->l_low)
		{
			if (ft_conversion_lchar(va_arg(*args, wint_t), flag, new))
				return (1);
		}
		else
			*new = ft_conversion_char(va_arg(*args, int), flag);
	}
	else if (*s == 's' || *s == 'S')
	{
		if (*s == 'S' || flag->l_low)
		{
			if (ft_conversion_lstr(va_arg(*args, wchar_t *), flag, new))
				return (1);
		}
		else
			*new = ft_conversion_str(va_arg(*args, const char *), flag);
	}
	return (0);
}

static int	ft_manage_conversion(va_list *args, t_flag *flag,
		char *s, char **out)
{
	char	*tmp;
	char	*new;
	int		nl;

	tmp = *out;
	nl = flag->null;
	ft_wildcard(args, flag);
	if (ft_ok_dioux(*s) || *s == 'b' || *s == 'B' || *s == 'p')
		new = ft_nb(args, s, flag);
	else if (*s == 'c' || *s == 'C' || *s == 's' || *s == 'S')
	{
		if (ft_conversion_c_n_s(args, s, flag, &new))
			return (1);
	}
	else if (flag->str)
		new = ft_strdup(flag->str);
	else if (*s == 'f' || *s == 'F')
		new = ft_conversion_double(ft_double_select(args, flag), flag, *s);
	else
		return (1);
	*out = ft_strjoin_hub(*out, new, flag->null, flag->null == nl ? 1 : 3);
	ft_strdel(&flag->str);
	ft_strdel(&tmp);
	ft_strdel(&new);
	return (0);
}

static int	ft_loop_args_extend(char **s, char **out,
			va_list *args, t_flag *flag)
{
	char	*tmp;

	tmp = *s;
	if (ft_ok_conv(**s))
	{
		if (ft_manage_conversion(args, flag, (*s)++, out))
			return (2);
		tmp++;
	}
	else if ((*s = ft_set_all_flags(tmp, flag)) && *s != tmp
			&& (flag->percent != 1 || flag->str))
	{
		if (ft_manage_conversion(args, flag, *s, out))
			return (2);
	}
	else if (!*s)
		return (1);
	if (**s && *s != tmp)
		(*s)++;
	else if ((flag->percent == 1 && flag->str)
			|| (**s == '%' && **s && !s[0][1] && ft_check_flag(flag)))
		ft_join_free(out, "%", 1, flag->null);
	if (!**s && flag->str)
		ft_join_free(out, flag->str, 1, 0);
	return (0);
}

int			ft_loop_args(char *s, va_list *args, char **out, t_flag *flag)
{
	int		ret;

	while (*s)
	{
		ft_init_flags(flag);
		if (!(s = ft_fillcstr(s, out, flag->null)))
			return (0);
		if (*s == '%')
		{
			ft_join_free(out, "%", 1, flag->null);
			s++;
		}
		else if ((ret = ft_loop_args_extend(&s, out, args, flag)) == 2)
			return (-1);
		else if (ret == 1)
			return (1);
		ft_strdel(&flag->str);
	}
	return (0);
}

int			ft_printf(const char *format, ...)
{
	char	*out;
	int		len;
	va_list	args;
	t_flag	flag;

	flag.null = 0;
	if (!format || !*format)
		return (0);
	out = NULL;
	va_start(args, format);
	len = ft_loop_args((char *)format, &args, &out, &flag);
	va_end(args);
	ft_strdel(&flag.str);
	if (len != -1)
	{
		len = ft_strlen_null(out, flag.null);
		write(1, out, len);
	}
	ft_strdel(&out);
	return (len);
}
