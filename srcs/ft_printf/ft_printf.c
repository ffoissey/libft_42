/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:29:32 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/07 18:32:36 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int64_t		get_numbers(int *nb, char *cur)
{
	uint8_t	i;

	i = 0;
	while (ft_isdigit(cur[i]) == TRUE)
		i++;
	if (i != 0)
		*nb = ft_atol(cur);
	return (i == 0 ? FAILURE : i);
}

int64_t		get_flag(t_machine *machine, char *cur, t_vector *out, va_list *arg)
{
	static const char	*flag[NB_FLAG] = {"hh", "ll", "h", "l", "L", "#", "0",
										"-", "+", " ", "."};
	uint8_t				i;
	ssize_t				len;

	i = 0;
	(void)out;
	(void)arg;
	while (i < NB_FLAG)
	{
		if (ft_strnequ(cur, flag[i]) == TRUE)
		{
			len = i < 2 ? 2 : 1;
			if (i < 5)
				machine->option.flag &= ~(ALL_MOD);
			machine->option.flag |= 1 << i;
			if (i == PRECISION_FLAG)
				len += get_numbers(&machine->option.precision, cur + len);
			break ;
		}
		i++;
	}
	if (i == NB_FLAG
		&& (len = get_numbers(&machine->option.field, cur)) == FAILURE)
		machine->state = STATE_CONV;
	return (len);
}

t_vector	*wildcard_conv(va_list *arg, t_option *option)
{
	(void)option;
	(void)arg;
	return (NULL);
}

t_vector	*c_conv(va_list *arg, t_option *option)
{
	(void)option;
	(void)arg;
	return (NULL);
}

t_vector	*s_conv(va_list *arg, t_option *option)
{
	(void)option;
	(void)arg;
	return (NULL);
}

t_vector	*boux_conv(va_list *arg, t_option *option)
{
	(void)option;
	(void)arg;
	return (NULL);
}

t_vector	*f_conv(va_list *arg, t_option *option)
{
	(void)option;
	(void)arg;
	return (NULL);
}

t_vector	*percent_conv(va_list *arg, t_option *option)
{
	(void)option;
	(void)arg;
	return (NULL);
}

t_vector	*none_conv(va_list *arg, t_option *option)
{
	(void)option;
	(void)arg;
	return (NULL);
}

t_vector	*p_conv(va_list *arg, t_option *option)
{
	(void)option;
	(void)arg;
	return (NULL);
}

int64_t		get_conv(t_machine *machine, char *cur, t_vector *out, va_list *arg)
{
	static t_func_conv	conv[] = {wildcard_conv, c_conv, c_conv, s_conv,
									s_conv, p_conv, boux_conv, di_conv,
									di_conv, di_conv, boux_conv, boux_conv,
									boux_conv, boux_conv, boux_conv, boux_conv,
									f_conv, f_conv, percent_conv, none_conv};
	static const char	conv[NB_CONV] = "*cCsSpbBdDioOuUxXfF%";
	uint8_t				i;

	i = 0;
	while (i < NB_CONV)
	{
		if (*cur == conv[i])
			break ;
		i++;
	}
	machine->option.flag |= (1 << i) + CONV_SCALE;
	vct_joinfree(out, conv[i](arg, &machine->option), SECOND);
	ft_bzero(machine, sizeof(t_machine));
	return (1);
}

int64_t		get_string(t_machine *machine, char *cur,
						t_vector *out, va_list *arg)
{
	char	*local;
	int64_t	len;

	len = 0;
	if (*cur != '\0')
	{	
		local = ft_strcdup(cur, FORMAT_CHAR);
		if (local != NULL)
		{
			len = vct_len(out);
			vct_addstr(out, local);
			len = vct_len(out) - len;
			if (cur[len] == FORMAT_CHAR)
				machine->state = STATE_FLAG;
		}
		ft_strdel(&local);
	}
	else
		machine->state = STATE_FINISH;
	return (len);
}

t_vector	*parser(const char *format)
{
	static t_func_machine	process[] = {get_string, get_flag, get_conv};
	t_vector				*out;
	size_t					i;
	va_list					args;
	t_machine				machine;

	ft_bzero(&machine, sizeof(t_machine));
	out = vct_new(ft_strlen(format) * 2);
	va_start(args, format);
	i = 0;
	machine->state = STATE_STRING;
	while (machine->state != STATE_FINISH)
	{
		if ((scale = process(machine, format + i, out, &arg)) != FAILURE)
			i += scale;
	}
	va_end(args);
	return (out);
}

int			ft_printf(const char *format, ...)
{
	t_vector	*out;
	int			write_ret;

	if (format == NULL || *format == '\0')
		return (0);
	write_ret = 0;
	out = parser(format);
	write_ret = write(STDOUT_FILENO, vct_getstr(vct), vct_len(vct));
	vct_del(&out);
	return (write_ret);
}
