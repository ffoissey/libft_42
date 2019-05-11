/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flags_extend.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 10:55:11 by ffoissey          #+#    #+#             */
/*   Updated: 2019/01/26 11:00:54 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_set_wildcard(t_flag *flag)
{
	if (flag->field && !flag->dot)
		flag->field = 0;
	flag->wildcard++;
}

void		ft_set_min_field_size(char **s, t_flag *flag)
{
	if (**s)
	{
		flag->field = ft_atoi(*s);
		if (*(*s + 1))
			while (*(*s + 1) >= '0' && *(*s + 1) <= '9')
				(*s)++;
	}
}

void		ft_set_precision(char **s, t_flag *flag)
{
	char	*tmp;

	flag->dot++;
	tmp = *s;
	(*s)++;
	if (**s)
	{
		if (**s < '0' || **s > '9')
		{
			*s = tmp;
			flag->precision = 0;
		}
		flag->precision = ft_atoi(*s);
		if (*(*s + 1))
			while (*(*s + 1) >= '0' && *(*s + 1) <= '9')
				(*s)++;
	}
}

void		ft_set_attribute_flags(char **s, t_flag *flag)
{
	if (**s == ' ')
		flag->space++;
	else if (**s == '#')
		flag->sharp++;
	else if (**s == '0')
		flag->zero++;
	else if (**s == '-')
		flag->min++;
	else if (**s == '+')
		flag->plus++;
}

void		ft_set_length_flags(char **s, t_flag *flag)
{
	if (!flag->ll)
	{
		if (**s == 'L')
			flag->l_up++;
		else if (**s == 'l')
		{
			if (*(*s + 1) == 'l')
			{
				flag->ll++;
				(*s)++;
			}
			else
				flag->l_low++;
		}
		else if (**s == 'h')
		{
			if (*(*s + 1) == 'h')
			{
				flag->hh++;
				(*s)++;
			}
			else
				flag->h++;
		}
	}
}
