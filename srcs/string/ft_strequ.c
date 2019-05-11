/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:08:10 by ffoissey          #+#    #+#             */
/*   Updated: 2018/11/09 11:42:25 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_strequ(char const *s1, char const *s2)
{
	if (!s1 && !s2)
		return (1);
	else if (!s1 || !s2)
		return (0);
	while (*s1 || *s2)
	{
		if (ft_isalpha(*s1))
			ft_toupper(*s1);
		if (ft_isalpha(*s2))
			ft_toupper(*s2);
		if (*s1++ != *s2++)
			return (0);
	}
	return (1);
}
