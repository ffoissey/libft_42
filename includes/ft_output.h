/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:25:10 by ffoissey          #+#    #+#             */
/*   Updated: 2019/03/14 15:58:34 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OUTPUT_H
# define FT_OUTPUT_H

# include <unistd.h>
# include "ft_string.h"

/*
***************
****  Char  ***
***************
*/

int			ft_putchar(char c);
int			ft_putchar_fd(char c, int fd);

/*
***************
***  String  **
***************
*/

int			ft_putstr(char const *s);
int			ft_putstr_fd(char const *s, int fd);
int			ft_putendl(char const *s);
int			ft_putendl_fd(char const *s, int fd);

/*
***************
**** Number  **
***************
*/

int			ft_putnbr(int n);
int			ft_putnbr_fd(int n, int fd);
int			ft_putnbr_base(int nbr, char *base);

/*
***************
****  Tab   ***
***************
*/

int			ft_print_inttab(int *tab, size_t size);
int			ft_print_strtab(char **tab);

/*
***************
**  Int Bit  **
***************
*/

int			ft_print_int_bits(int m);

#endif
