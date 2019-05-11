/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_operate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 10:09:22 by ffoissey          #+#    #+#             */
/*   Updated: 2019/01/26 10:12:44 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_double.h"

int			ft_check_zero_mantissa(int *tab)
{
	int		i;

	i = 1;
	while (i < 64)
		if (tab[i++] == 1)
			return (0);
	return (1);
}

static void	ft_align(char **s1, char **s2)
{
	int		len;
	char	*tmp;

	if (ft_strlen(*s1) > ft_strlen(*s2))
	{
		len = ft_strlen(*s1);
		tmp = ft_strnew(len);
		ft_fill_with_zero(tmp, len);
		ft_str_rev_cpy(tmp, *s2);
		ft_strdel(s2);
		*s2 = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	else if (ft_strlen(*s1) < ft_strlen(*s2))
	{
		len = ft_strlen(*s2);
		tmp = ft_strnew(len);
		ft_fill_with_zero(tmp, len);
		ft_str_rev_cpy(tmp, *s1);
		ft_strdel(s1);
		*s1 = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
}

char		*ft_power_of_two(char *s)
{
	char	*ret;
	int		len;

	len = ft_strlen(s) + 1;
	ret = ft_strnew(len);
	ft_fill_with_zero(ret, len);
	ft_str_rev_cpy(ret, s);
	ret = ft_addition(ret, ft_strdup(ret));
	return (ret);
}

char		*ft_get_int(int *tab, int size, int max)
{
	char		*nb;
	char		*tmp;
	char		*tmp_ret;

	nb = ft_strdup("0");
	tmp = ft_strdup("1");
	while (--size > max)
		ft_dup(&tmp, ft_power_of_two(tmp));
	while (size >= 0)
	{
		if (tab[size--])
		{
			tmp_ret = ft_strdup(tmp);
			ft_align(&tmp, &nb);
			nb = ft_addition(tmp_ret, nb);
		}
		ft_dup(&tmp, ft_power_of_two(tmp));
	}
	tmp_ret = nb;
	while (*nb == '0')
		nb++;
	nb = ft_strdup(nb);
	ft_strdel(&tmp_ret);
	ft_strdel(&tmp);
	return (nb);
}
