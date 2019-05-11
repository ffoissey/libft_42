/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:25:10 by ffoissey          #+#    #+#             */
/*   Updated: 2019/03/14 15:58:34 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_H
# define FT_MEMORY_H

# include <stdlib.h>

/*
***************
**** Search ***
***************
*/

void		*ft_memchr(const void *s, int c, size_t n);

/*
***************
****  Comp  ***
***************
*/

int			ft_memcmp(const void *s1, const void *s2, size_t n);

/*
***************
****  Copy  ***
***************
*/

void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);

/*
***************
****  Free  ***
***************
*/

void		ft_memdel(void **ap);

/*
***************
***  Alloc  ***
***************
*/

void		*ft_memalloc(size_t size);

/*
***************
****  Set   ***
***************
*/

void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);

/*
***************
****  Bits  ***
***************
*/

int			ft_inverse_bits(int c);
int			ft_swap_bits(int c);

#endif
