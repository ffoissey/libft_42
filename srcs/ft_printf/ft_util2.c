/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 12:28:45 by ffoissey          #+#    #+#             */
/*   Updated: 2019/01/26 11:35:45 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_largechar(unsigned int c, char **to_free)
{
	if ((c >= 0xd800 && c <= 0xdfff)
		|| (c > 0x10FFFF))
	{
		if (to_free)
			ft_strdel(to_free);
		return (0);
	}
	return (1);
}

int		ft_ret_largechar(unsigned int c)
{
	if (c < 128)
		return (1);
	else if (c < 2048)
		return (2);
	else if (c < 65536)
		return (3);
	else
		return (4);
}

char	*ft_strnew_c(size_t size, char c)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
		str[i++] = c;
	str[i] = '\0';
	return (str);
}

void	ft_filler(char **s, char *add, int after, int null)
{
	char	*tmp;

	tmp = *s;
	if (!after || (add && *add != ' '))
		*s = ft_strjoin_hub(add, *s, null, 2);
	else
		*s = ft_strjoin_hub(*s, add, null, 1);
	ft_strdel(&tmp);
	ft_strdel(&add);
}

void	ft_join_free(char **s, char const *new, int after, int null)
{
	char	*tmp;

	tmp = *s;
	if (after)
		*s = ft_strjoin_hub(*s, new, null, 1);
	else
		*s = ft_strjoin_hub(new, *s, null, 2);
	ft_strdel(&tmp);
}
