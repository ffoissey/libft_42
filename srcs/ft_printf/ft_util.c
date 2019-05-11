/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 12:29:00 by ffoissey          #+#    #+#             */
/*   Updated: 2019/01/28 16:30:41 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_ok_conv(char c)
{
	return (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x'
			|| c == 'D' || c == 'O' || c == 'U' || c == 'X' || c == 'B'
			|| c == 'b' || c == 'p' || c == 'f' || c == 'F'
			|| c == 's' || c == 'S' || c == 'c' || c == 'C');
}

int			ft_ok_dioux(char c)
{
	return (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x'
			|| c == 'D' || c == 'O' || c == 'U' || c == 'X');
}

size_t		ft_strlen_null(const char *s, int null)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	if (null <= 0)
		return (ft_strlen(s));
	if (!s)
		return (0);
	while (s[len] || null)
	{
		if (s[len] == '\0')
			null--;
		len++;
	}
	return (len);
}

char		*ft_strjoin_null(char const *s1, char const *s2, int null, int id)
{
	char	*s_new;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 && !s2)
		return (NULL);
	if (id == 3)
	{
		len_s2 = ft_strlen_null(s2, 1);
		len_s1 = (null - 1) > 0 ? ft_strlen_null(s1, null - 1)
			: ft_strlen(s1);
	}
	else
	{
		len_s1 = (id == 1 ? ft_strlen_null(s1, null) : ft_strlen(s1));
		len_s2 = (id == 2 ? ft_strlen_null(s2, null) : ft_strlen(s2));
	}
	if (!(s_new = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (NULL);
	ft_memcpy(s_new, s1, len_s1);
	ft_memcpy(s_new + len_s1, s2, len_s2);
	s_new[len_s1 + len_s2] = '\0';
	return (s_new);
}

char		*ft_strjoin_hub(const char *s1, const char *s2, int null, int id)
{
	if (null)
		return (ft_strjoin_null(s1, s2, null, id));
	else
		return (ft_strjoin(s1, s2));
}
