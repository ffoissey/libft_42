/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_whitespaces.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:51:30 by ffoissey          #+#    #+#             */
/*   Updated: 2020/04/28 20:42:24 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_memory.h"

static size_t	ft_count_words(char const *s)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i++])
	{
		if (s[i] == ' ' || s[i] == '\t' || !s[i])
		{
			if (s[i - 1] != ' ' && s[i - 1] != '\t')
				count++;
		}
	}
	return (count);
}

static void		free_table(char **tab, size_t master_i)
{
	size_t	i;

	i = 0;
	while (i < master_i)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
}

static char		**ft_fill_table(char const *s, char **tab)
{
	size_t	i;
	size_t	j;
	size_t	master_i;

	i = 0;
	j = 0;
	master_i = 0;
	while (s[i++])
	{
		if (s[i] == ' ' || s[i] == '\t' || !s[i])
		{
			if (!(tab[master_i] = (char *)malloc(sizeof(char) * (i - j + 1))))
			{
				free_table(tab, master_i);
				return (NULL);
			}
			ft_strncpy(tab[master_i], s + j, i - j);
			tab[master_i++][i - j] = '\0';
			while (s[i] == ' ' || s[i] == '\t')
				i++;
			j = i;
		}
	}
	return (tab);
}

char			**ft_strsplit_whitespaces(char const *s)
{
	char				**tab;
	size_t				count;
	size_t				i;

	if (!s)
		return (NULL);
	i = 0;
	count = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i])
		count = ft_count_words(s);
	if (!(tab = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	ft_bzero(tab, sizeof(char *) * (count + 1));
	if (count)
	{
		if (!(tab = ft_fill_table(s + i, tab)))
		{
			free(tab);
			tab = NULL;
			return (NULL);
		}
	}
	return (tab);
}
