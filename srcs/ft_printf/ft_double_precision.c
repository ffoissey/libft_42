/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 10:09:30 by ffoissey          #+#    #+#             */
/*   Updated: 2020/04/22 17:25:02 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_double.h"

static void	ft_process_carry(char *s)
{
	int		carry;
	int		i;

	i = (int)ft_strlen(s) - 1;
	carry = 1;
	while (i > 0 && s[i] == '9' && carry == 1 && s[i] != '.')
	{
		carry = 0;
		if (s[i - 1] == '.')
			i--;
		if (s[i - 1] < '9')
			s[i - 1]++;
		else
			carry = 1;
		if (s[i] == '.')
			s[i + 1] = '0';
		else
			s[i] = '0';
		i--;
	}
}

static char	*ft_carry(char **tmp)
{
	char	*s;
	int		i;
	char	*tmp_s;

	s = ft_strnew(ft_strlen(*tmp) + 1);
	s[0] = '0';
	i = 1;
	while (tmp[0][i - 1])
	{
		s[i] = tmp[0][i - 1];
		i++;
	}
	ft_strdel(tmp);
	ft_process_carry(s);
	if (s[0] == '0')
	{
		tmp_s = s;
		s = ft_strdup(s + 1);
		ft_strdel(&tmp_s);
	}
	s[ft_strlen(s) - 1] = '\0';
	return (s);
}

static int	ft_all_zero(char *tmp, int i)
{
	while (tmp[i])
		if (tmp[i++] != '0')
			return (1);
	return (0);
}

static void	ft_prepare_carry(char **tmp, int i)
{
	if (tmp[0][i] >= '5' && !ft_all_zero((*tmp) + 1, i))
	{
		if (i > 0 && tmp[0][i - 1] < '5')
			tmp[0][i] = '0';
	}
	if (i && tmp[0][i] >= '5')
	{
		tmp[0][i + 1] = '\0';
		tmp[0][i] = '9';
		*tmp = ft_carry(tmp);
	}
	else
		tmp[0][i] = '\0';
}

void		ft_get_prec(char **exp, int prec)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strdup(*exp);
	while (tmp[i] && tmp[i] != '.')
		i++;
	i++;
	while (tmp[i] && prec)
	{
		i++;
		prec--;
	}
	if (tmp[i])
		ft_prepare_carry(&tmp, i);
	else
		tmp[i] = '\0';
	while (prec-- > 0)
		ft_join_free(&tmp, "0", 1, 0);
	ft_dup(exp, ft_strdup(tmp));
	ft_strdel(&tmp);
}
