/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_large.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:06:34 by ffoissey          #+#    #+#             */
/*   Updated: 2020/04/22 17:34:12 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_three_bytes(unsigned int m, char *s)
{
	unsigned int	tmp_m;
	unsigned int	tmp;
	unsigned int	c;

	tmp_m = m;
	tmp = m % 64;
	m -= tmp;
	c = THREE_BYTES + tmp;
	if (tmp_m <= 0x0FFF)
		c += (m << 2);
	else
	{
		m <<= 2;
		tmp = m % 16384;
		m -= tmp;
		c += tmp + (m << 2);
	}
	s[2] = (char)c;
	s[1] = (char)(c >> 8);
	s[0] = (char)(c >> 16);
}

static void		ft_four_bytes(unsigned int m, char *s)
{
	unsigned int	tmp_m;
	unsigned int	tmp;
	unsigned int	c;

	tmp_m = m;
	tmp = m % 64;
	m -= tmp;
	c = FOUR_BYTES + tmp;
	m <<= 2;
	tmp = m % 16384;
	m -= tmp;
	c += tmp;
	if (tmp_m <= 0x3FFFF)
		c += (m << 2);
	else
	{
		m <<= 2;
		tmp = m % 4194304;
		m -= tmp;
		c += tmp + (m << 2);
	}
	s[3] = (char)c;
	s[2] = (char)(c >> 8);
	s[1] = (char)(c >> 16);
	s[0] = (char)(c >> 24);
}

static char		*ft_utf8(unsigned int m, int ret)
{
	unsigned int	c;
	unsigned int	tmp;
	char			*s;

	s = ft_strnew((size_t)ret);
	if (ret == 1)
		s[0] = (char)m;
	else if (ret == 2)
	{
		tmp = m % 64;
		m -= tmp;
		c = TWO_BYTES + tmp + (m << 2);
		s[1] = (char)c;
		s[0] = (char)(c >> 8);
	}
	else if (ret == 3)
		ft_three_bytes(m, s);
	else
		ft_four_bytes(m, s);
	return (s);
}

int				ft_conversion_lchar(wint_t c, t_flag *flag, char **new)
{
	char	*tmp;
	int		ret;

	if (!ft_check_largechar(c, NULL))
		return (1);
	ret = ft_ret_largechar(c);
	if (ret == 1)
	{
		*new = ft_conversion_char((int)c, flag);
		return (0);
	}
	tmp = ft_utf8(c, ret);
	*new = ft_conversion_str(tmp, flag);
	ft_strdel(&tmp);
	return (0);
}

int				ft_conversion_lstr(wchar_t *src, t_flag *flag, char **new)
{
	char	*s;
	char	*tmp;
	int		ret;
	int		i;
	int		tmp_prec;

	i = -1;
	tmp = NULL;
	s = NULL;
	tmp_prec = (int)flag->precision;
	while (src && src[++i])
	{
		if (!ft_check_largechar((unsigned int)src[i], &tmp))
			return (1);
		ret = ft_ret_largechar((unsigned int)src[i]);
		if (!flag->dot || (flag->dot && ((tmp_prec -= ret) >= 0)))
			ft_join_free(&tmp, (s = ft_utf8((unsigned int)src[i], ret)), 1, 0);
		else if (flag->dot && tmp_prec < 0 && i == 0)
			tmp = ft_strnew(1);
		ft_strdel(&s);
	}
	tmp = (src && !src[0]) ? ft_strnew(1) : tmp;
	*new = ft_conversion_str(tmp, flag);
	ft_strdel(&tmp);
	return (0);
}
