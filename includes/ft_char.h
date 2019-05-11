/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:25:10 by ffoissey          #+#    #+#             */
/*   Updated: 2019/03/14 15:58:34 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHAR_H
# define FT_CHAR_H

# include "define_libft.h"

/*
***************
** Transform **
***************
*/

int		ft_toupper(int c);
int		ft_tolower(int c);

/*
***************
****  Test  ***
***************
*/

int		ft_islower(int c);
int		ft_isupper(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isblank(int c);
int		ft_iscntrl(int c);
int		ft_isgraph(int c);
int		ft_isspace(int c);
int		ft_isxdigit(int c);

#endif
