/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:21:18 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/10 16:23:42 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int		ft_strcheck(char *s, int (*f)(int))
{
	unsigned int i;

	i = 0;
	if (!s || !f)
		return (FALSE);
	while (s[i] != '\0')
	{
		if (f(s[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
