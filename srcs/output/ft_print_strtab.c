/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_strtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:28:04 by ffoissey          #+#    #+#             */
/*   Updated: 2018/11/28 17:28:08 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_output.h"

int	ft_print_strtab(char **tab)
{
	int ret;

	ret = 0;
	if (!tab)
		return (0);
	while (*tab)
		ret = ft_putendl(*tab++);
	return (ret);
}
