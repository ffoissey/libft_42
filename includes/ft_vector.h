/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 18:23:42 by ffoissey          #+#    #+#             */
/*   Updated: 2019/08/31 22:24:22 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include "libft.h"
# define DFL_VCT_SIZE		64
# define DFL_VCT_SCALE		16

typedef struct	s_vector
{
	char		*str;
	size_t		size;
	size_t		scale;
	size_t		len;
}				t_vector;

t_vector	*vct_new(size_t size);
void		vct_reset(t_vector *vct);
void		vct_del(t_vector **vct);
int			vct_extend(t_vector *vector, size_t size);
int			vct_add(t_vector *vector, char c);
int			vct_push(t_vector *vector, char c);
int			vct_pop(t_vector *vector);
int			vct_cut(t_vector *vector);

/*
** cut from
** pop from
** cut til
** pop til
** join
** dup
** add_string
** push_string
** 
*/

#endif
