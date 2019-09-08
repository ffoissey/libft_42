/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:29:32 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/08 22:01:52 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint64_t		get_numbers(uint64_t *nb, char *cur)
{
	uint8_t	i;

	i = 0;
	while (ft_isdigit(cur[i]) == TRUE)
		i++;
	*nb = ft_atol(cur);
	return (i);
}

int64_t		get_flag(t_machine *machine, char *cur, t_vector *out, va_list *arg)
{
	static const char	*flag[NB_FLAG] = {"hh", "ll", "h", "l", "L", "#", "0",
										"-", "+", " ", "."};
	uint8_t				i;
	uint64_t			len;

	i = 0;
	(void)out;
	(void)arg;
	while (i < NB_FLAG)
	{
		len = i < 2 ? 2 : 1;
		if (ft_strnequ(cur, flag[i], len) == TRUE)
		{
			if (i < 5)
				machine->option.flag &= ~(ALL_MOD);
			machine->option.flag |= 1 << i;
			if (i == PRECISION_FLAG)
				len += get_numbers(&machine->option.precision, cur + len);
			break ;
		}
		i++;
	}
	if (i == NB_FLAG)
	{
		if (ft_isdigit(*cur) == TRUE)
			len = get_numbers(&machine->option.field, cur);
		else
		{
			len = 0;
			machine->state = STATE_CONV;
		}
	}
	return (len == 0 ? FAILURE : len);
}

t_vector	*wildcard_conv(va_list *arg, t_option *option)
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

int64_t		get_conv(t_machine *machine, char *cur, t_vector *out, va_list *arg)
{
	static t_func_conv	conv[] = {wildcard_conv, c_conv, c_conv, s_conv,
									s_conv, pboux_conv, pboux_conv, pboux_conv,
									di_conv, di_conv, di_conv, pboux_conv,
									pboux_conv, pboux_conv, pboux_conv, pboux_conv,
									pboux_conv, f_conv, f_conv, c_conv, c_conv};
	static const char	conv_char[NB_CONV] = "*cCsSpbBdDioOuUxXfF%";
	t_vector			*local;
	uint8_t				i;

	i = 0;
	if (*cur == '\0')
	{
		machine->state = STATE_FINISH;
		return (0);
	}
	while (i < NB_CONV - 1)
	{
		if (*cur == conv_char[i])
			break ;
		i++;
	}
	machine->option.flag |= (((uint64_t)1 << i) << CONV_SHIFT);
	if (i > 18)
		machine->option.flag |= (((uint64_t)(*cur)) << CHAR_ERR_SHIFT);
	local = conv[i](arg, &machine->option);
	vct_cat(out, local);
	vct_del(&local);
	ft_bzero(machine, sizeof(t_machine));
	return (1);
}

int64_t		get_string(t_machine *machine, char *cur,
						t_vector *out, va_list *arg)
{
	int64_t	len;

	len = 0;
	(void)arg;
	while (cur[len] != '\0' && cur[len] != FORMAT_CHAR)
		vct_add(out, cur[len++]);
	machine->state = STATE_FLAG;
	if (cur[len] == '\0')
	{
		machine->state = STATE_FINISH;
		len = 0;
	}
	else
		len++;
	return (len);
}

int8_t	parser(char *format, t_vector *out, va_list *arg)
{
	static t_func_machine	process[] = {get_string, get_flag, get_conv};
	int64_t					i;
	int64_t					scale;
	t_machine				machine;

	ft_bzero(&machine, sizeof(t_machine));
	i = 0;
	machine.state = STATE_STRING;
	while (machine.state != STATE_FINISH)
	{
		scale = process[machine.state](&machine, format + i, out, arg);
		if (scale != FAILURE)
			i += scale;
	}
	return (SUCCESS);
}

int			ft_printf(const char *format, ...)
{
	t_vector	*out;
	va_list		arg;
	int			write_ret;

	if (format == NULL || *format == '\0')
		return (0);
	out = vct_new(ft_strlen(format) * 2);
	va_start(arg, format);
	parser((char *)format, out, &arg);
	va_end(arg);
	write_ret = write(STDOUT_FILENO, vct_getstr(out), vct_len(out));
	vct_del(&out);
	return (write_ret);
}
