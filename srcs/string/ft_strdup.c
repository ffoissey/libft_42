/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:20:05 by ffoissey          #+#    #+#             */
/*   Updated: 2018/11/13 11:18:49 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strdup(const char *s1)
{
	char	*new_str;

	new_str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (new_str == NULL)
		return (NULL);
	return (ft_strcpy(new_str, s1));
}
