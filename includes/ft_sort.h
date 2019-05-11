/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:25:10 by ffoissey          #+#    #+#             */
/*   Updated: 2019/03/14 15:58:34 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SORT_H
# define FT_SORT_H

# include <string.h>
# include "ft_string.h"

/*
***************
**** Bubble ***
***************
*/

void		ft_bubblesort_strtab(char **tab);
void		ft_bubblesort_integer(int *tab, size_t size);

/*
***************
** Insertion **
***************
*/

void		ft_insertsort_integer(int *tab, size_t size);
void		ft_insertsort_long(long *tab, size_t size);
void		ft_insertsort_strtab(char **tab);

#endif
