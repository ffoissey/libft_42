/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_mantissa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 10:09:12 by ffoissey          #+#    #+#             */
/*   Updated: 2019/01/26 12:29:37 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_double.h"

static void	ft_set_mantisse_extend2(char *m, int *tab, int size, int i)
{
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P41)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P42)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P43)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P44)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P45)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P46)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P47)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P48)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P49)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P50)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P51)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P52)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P53)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P54)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P55)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P56)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P57)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P58)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P59)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P60)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P61)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P62)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P63)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P64)) : m;
}

static void	ft_set_mantisse_extend1(char *m, int *tab, int size, int i)
{
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P17)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P18)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P19)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P20)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P21)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P22)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P23)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P24)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P25)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P26)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P27)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P28)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P29)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P30)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P31)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P32)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P33)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P34)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P35)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P36)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P37)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P38)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P39)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P40)) : m;
	ft_set_mantisse_extend2(m, tab, size, i);
}

char		*ft_set_mantisse(int *tab, int size)
{
	char	*m;
	int		i;

	i = 0;
	m = ft_strdup(P0);
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P1)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P2)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P3)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P4)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P5)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P6)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P7)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P8)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P9)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P10)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P11)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P12)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P13)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P14)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P15)) : m;
	m = i < size && tab[i++] ? ft_addition(m, ft_strdup(P16)) : m;
	ft_set_mantisse_extend1(m, tab, size, i);
	return (m);
}
