/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:38:53 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/05 15:39:01 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_base(const char *base)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (base[i] != '\0')
	{
		if (ft_isprint(base[i]) == 0 || base[i] == '+' || base[i] == '-')
			return (1);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j] && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	is_into_base(const char *base, char c)
{
	int		i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_atoi_process(const char *str, const char *base, int nb_base)
{
	int				nbr;
	int				index;
	size_t			i;

	nbr = 0;
	i = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		i++;
	while ((index = is_into_base(base, str[i])) != -1)
	{
		nbr = nbr * nb_base + index;
		i++;
	}
	return (str[0] == '-' ? -nbr : nbr);
}

int			ft_atoi_base(const char *str, const char *base)
{
	int				nb_base;

	if (base == NULL)
		return (0);
	nb_base = ft_strlen(base);
	if (nb_base < 2 || check_base(base) == 1)
		return (0);
	return (ft_atoi_process(str, base, nb_base));
}
