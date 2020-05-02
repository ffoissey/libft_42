/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_extend.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 10:09:00 by ffoissey          #+#    #+#             */
/*   Updated: 2020/04/22 17:29:18 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_double.h"

void		ft_dup(char **src, char *s)
{
	ft_strdel(src);
	*src = s;
}

void		ft_fill_with_zero(char *s, int size)
{
	while (size)
		s[--size] = '0';
}

void		ft_str_rev_cpy(char *dest, char *src)
{
	size_t	len_src;
	size_t	len;

	len_src = ft_strlen(src);
	len = ft_strlen(dest);
	while (len_src)
		dest[--len] = src[--len_src];
}

static void	ft_process_addition(char *m, char *s, size_t size)
{
	char	*carry;
	int		res;
	char	*empty;
	size_t	tmp;

	tmp = size;
	carry = ft_strnew(size);
	ft_fill_with_zero(carry, (int)size);
	empty = ft_strnew(size);
	ft_fill_with_zero(empty, (int)size);
	while (size-- > 0)
	{
		if ((res = (m[size] - '0' + s[size] - '0')) > 9)
		{
			m[size] = (char)(res % 10 + '0');
			if (size - 1 > 0)
				carry[size - 1] = (char)(res / 10 + '0');
		}
		else
			m[size] = (char)(res + '0');
	}
	if (ft_strcmp(carry, empty) && tmp)
		ft_process_addition(m, carry, tmp);
	ft_strdel(&carry);
	ft_strdel(&empty);
}

char		*ft_addition(char *m, char *s)
{
	size_t	len;

	len = ft_strlen(m);
	ft_process_addition(m, s, len);
	ft_strdel(&s);
	return (m);
}
