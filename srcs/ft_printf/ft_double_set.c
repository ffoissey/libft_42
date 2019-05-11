/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 10:09:38 by ffoissey          #+#    #+#             */
/*   Updated: 2019/01/26 10:40:00 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_double.h"

void		ft_sign_and_exp(int *m, int *exp_pow)
{
	int		exp;
	int		tmp;
	int		i;

	exp = 0;
	tmp = 1;
	i = 15;
	exp = m[i--] == 1 ? exp + tmp : exp;
	while (i > 0)
	{
		tmp *= 2;
		exp = m[i--] == 1 ? exp + tmp : exp;
	}
	*exp_pow = exp - 16383;
}

void		ft_mantisse(int *m, int *tab, int size)
{
	int		i;

	i = 0;
	m += 16;
	while (i < size)
	{
		tab[i] = m[i];
		i++;
	}
}

void		ft_set_ptr(void *ptr, int *tab)
{
	int				i;
	int				j;
	char			tmp;
	unsigned char	*c_ptr;

	i = 79;
	c_ptr = (unsigned char *)ptr;
	while (i >= 0)
	{
		j = 0;
		while (j < 8 && i >= 0)
		{
			tmp = *c_ptr;
			tmp = (tmp >> j++) & 1;
			tab[i--] = tmp && 1 ? 1 : 0;
		}
		c_ptr++;
	}
}

static void	ft_zero_extend(char *tab, long double zero)
{
	int		count;

	count = 0;
	tab[64] = '\0';
	while (count < 64)
	{
		tab[count++] = (int)zero + '0';
		zero -= (int)zero;
		zero *= 10.0;
	}
}

char		*ft_zero(void *ptr)
{
	long double zero;
	int			count;
	char		*tab_z;
	char		tab[65];

	zero = *(long double *)ptr;
	count = 0;
	if (zero < 0)
		zero = -zero;
	while ((int)zero == 0)
	{
		zero -= (int)zero;
		zero *= 10.0;
		count++;
	}
	tab_z = ft_strnew(count);
	tab_z[count-- - 1] = '\0';
	ft_zero_extend(tab, zero);
	while (count-- > 0)
		tab_z[count] = '0';
	ft_join_free(&tab_z, tab, 1, 0);
	return (tab_z);
}
