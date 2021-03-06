/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:01:00 by ffoissey          #+#    #+#             */
/*   Updated: 2020/04/22 16:57:21 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"

int	ft_toupper(int c)
{
	return ((c >= 97 && c <= 122) ? (c - 32) : c);
}
