/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:25:10 by ffoissey          #+#    #+#             */
/*   Updated: 2020/03/11 17:34:07 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERSION_H
# define FT_CONVERSION_H

# include "define_libft.h"
# include <string.h>

/*
****************
** Str to Int **
****************
*/

int			ft_atoi(const char *str);
int			ft_atoi_base(const char *str, const char *base);
long		ft_atol(const char *str);

/*
****************
** Int to Str **
****************
*/

char		*ft_itoa(int n);
char		*ft_itoa_base(int value, int base);

#endif
