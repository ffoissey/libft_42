/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:52:31 by ffoissey          #+#    #+#             */
/*   Updated: 2018/11/12 15:08:05 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strcdup(char *s1, char c)
{
	char	*new_str;

	new_str = ft_strsub(s1, 0, ft_strclen(s1, c));
	return (new_str);
}
