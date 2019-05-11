/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_hub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 10:08:48 by ffoissey          #+#    #+#             */
/*   Updated: 2019/01/26 10:08:50 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_double.h"

static void	ft_exp_neg(char **exp, void *ptr)
{
	char *mantisse;
	char *tmp;

	mantisse = ft_zero(ptr);
	*exp = ft_strjoin("0.", *exp);
	tmp = *exp;
	*exp = ft_strjoin(*exp, mantisse);
	ft_strdel(&tmp);
	ft_strdel(&mantisse);
}

static void	ft_exp_pos(char **exp, int *tab, int exp_pow)
{
	char	*tmp;
	char	*mantisse;

	*exp = ft_get_int(tab, exp_pow + 1, LONG_DOUBLE);
	tmp = *exp;
	*exp = ft_strjoin(*exp, ".");
	ft_strdel(&tmp);
	mantisse = ft_set_mantisse(exp_pow > (LONG_DOUBLE - 1) ? NULL
				: tab + exp_pow + 1, LONG_DOUBLE - exp_pow - 1);
	tmp = *exp;
	*exp = ft_strjoin(*exp, mantisse + 1);
	ft_strdel(&tmp);
	ft_strdel(&mantisse);
}

char		*ft_dtoa(void *ptr, int prec)
{
	int		tab[64];
	int		tab_master[80];
	int		exp_pow;
	char	*exp;

	exp = NULL;
	ft_set_ptr(ptr, tab_master);
	ft_sign_and_exp(tab_master, &exp_pow);
	ft_mantisse(tab_master, tab, LONG_DOUBLE);
	if (exp_pow > 16383)
		exp = ft_strdup(ft_check_zero_mantissa(tab) ? "inf" : "nan");
	else
	{
		if (exp_pow == -16383)
			exp = ft_strdup("0.000000");
		else if (exp_pow < 0)
			ft_exp_neg(&exp, ptr);
		else
			ft_exp_pos(&exp, tab, exp_pow);
		ft_get_prec(&exp, prec);
	}
	if (exp[0] != 'n' && tab_master[0] == 1)
		ft_join_free(&exp, "-", 0, 0);
	return (exp);
}
