/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_mantissa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 10:09:12 by ffoissey          #+#    #+#             */
/*   Updated: 2020/04/22 16:08:00 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_double.h"

static char	*get_tab_mantisse(const int i)
{
	static char	*mantisse[] = {P1, P21, P3, P4, P5, P6, P7, P8, P9, P10,
							P11, P12, P13, P14, P15, P16, P17, P18, P19, P20,
							P21, P22, P23, P24, P25, P26, P27, P28, P29, P30,
							P31, P32, P33, P34, P35, P36, P37, P38, P39, P40,
							P41, P42, P43, P44, P45, P46, P47, P48, P49, P50,
							P51, P52, P53, P54, P55, P56, P57, P58, P59, P60,
							P61, P62, P63, P64};

	return (mantisse[i]);
}

char		*ft_set_mantisse(int *tab, int size)
{
	char	*m;
	int		i;

	i = 0;
	m = ft_strdup(P0);
	while (i < size)
	{
		if (tab[i] != 0)
		{
			m = ft_addition(m, ft_strdup(get_tab_mantisse(i)));
			i++;
		}
	}
	return (m);
}
