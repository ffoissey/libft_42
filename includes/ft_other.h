/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:25:10 by ffoissey          #+#    #+#             */
/*   Updated: 2019/05/18 18:17:23 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OTHER_H
# define FT_OTHER_H

# include "define_libft.h"

/*
***************
**    Swap   **
***************
*/

void		ft_swap(int *a, int *b);
void		ft_swap_addr(void **a, void **b);

/*
***************
**    Read   **
***************
*/

char		*ft_read_all(int fd);

#endif
