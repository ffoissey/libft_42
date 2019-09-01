/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 18:23:42 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/01 19:50:34 by ffoissey         ###   ########.fr       */
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

t_vector		*vct_new(size_t size);
t_vector		*vct_newstr(char *str);
t_vector		*vct_reset(t_vector *vct, size_t size);
void			vct_clear(t_vector *vct);
void			vct_del(t_vector **vct);
int				vct_extend(t_vector *vector, size_t size);
int				vct_add(t_vector *vector, char c);
int				vct_charat(t_vector *vct, char c, size_t index);
int				vct_push(t_vector *vector, char c);
int				vct_pop(t_vector *vector);
int				vct_popfrom(t_vector *vector, size_t index);
int				vct_cut(t_vector *vector);
int				vct_cutfrom(t_vector *vector, size_t index);
t_vector		*vct_dup(t_vector *vector);
t_vector		*vct_ndup(t_vector *vector, size_t n);
t_vector		*vct_cdup(t_vector *vector, char c);
size_t			vct_len(t_vector *vector);
char			*vct_getstr(t_vector *vector);
char			*vct_dupstr(t_vector *vector);
int				vct_cpy(t_vector *dest, t_vector *src);
int				vct_cat(t_vector *dest, t_vector *src);
t_vector		*vct_join(t_vector *vct1, t_vector *vct2);
t_vector		*vct_joinfree(t_vector **vct1, t_vector **vct2, int flag);
int				vct_addstr(t_vector *dest, char *src);
int				vct_pushstr(t_vector *dest, char *src);
t_vector		*vct_sub(t_vector *vct, size_t start, size_t end);
void			vct_replacechar(t_vector *vector, char to_replace, char by);
int				vct_replacestr(t_vector *vector, char *to_replace, char *by);
void			vct_apply(t_vector *vct, char *(*f)(char *));
int				vct_strcheck(t_vector *vct, int (*f)(char *));

#endif
