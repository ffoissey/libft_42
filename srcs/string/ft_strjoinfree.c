/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 12:28:45 by ffoissey          #+#    #+#             */
/*   Updated: 2019/01/26 11:35:45 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strjoinfree_n(char **s1, char **s2, int which)
{
	char	*new_str;

	new_str = ft_strjoin(*s1, *s2);
	if (which == FIRST || which == BOTH)
		ft_strdel(s1);
	if (which == SECOND || which == BOTH)
		ft_strdel(s2);
	return (new_str);
}

char	*ft_strjoinfree(char *s1, char *s2, int which)
{
	char	*new_str;

	new_str = ft_strjoin(s1, s2);
	if (which == FIRST || which == BOTH)
		ft_strdel(&s1);
	if (which == SECOND || which == BOTH)
		ft_strdel(&s2);
	return (new_str);
}
