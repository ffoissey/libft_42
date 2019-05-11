/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:23:42 by ffoissey          #+#    #+#             */
/*   Updated: 2018/11/07 16:35:22 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*new_s;

	if (!s || !f)
		return (NULL);
	if (!(new_s = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_s[i] = f(s[i]);
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
