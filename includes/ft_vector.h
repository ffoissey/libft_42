/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 18:23:42 by ffoissey          #+#    #+#             */
/*   Updated: 2020/05/01 14:26:35 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include "libft.h"
# include <limits.h>
# include <stdint.h>

# define DFL_VCT_SIZE		64
# define DFL_VCT_SCALE		16
# define VCT_LIMIT			INT_MAX

# define NB_INT_FT			12
# define NB_CHAR_PTR_FT		4

# define LINE_OK			1
# define IS_EOF				0

# define NO_SEP				0x01
# define EACH_SEP			0x02
# define ALL_SEP			0x04
# define INIT				0x08

# define KEEP_CHAR			0
# define DEL_CHAR			1

typedef struct	s_vector
{
	char		*str;
	size_t		len;
	size_t		size;
	size_t		scale;
}				t_vector;

typedef	int		(*t_int_funct)(int c);
typedef	char	*(*t_char_ptr_funct)(char *);

enum	e_apply
{
	IS_LOWER,
	IS_UPPER,
	IS_ALPHA,
	IS_DIGIT,
	IS_ALNUM,
	IS_ASCII,
	IS_PRINTABLE,
	IS_BLANK,
	IS_CNTRL,
	IS_GRAPH,
	IS_SPACE,
	IS_XDIGIT,
	UPCASE,
	LOWCASE,
	CAPITAL,
	REV,
	IS_NUMBER,
	EMPTY
};

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
size_t			vct_nlen(t_vector *vct, size_t n);
size_t			vct_clen(t_vector *vct, char c);
char			*vct_getstr(t_vector *vector);
char			*vct_dupstr(t_vector *vector);
int				vct_cpy(t_vector *dest, t_vector *src);
int				vct_cat(t_vector *dest, t_vector *src);
t_vector		*vct_join(t_vector *vct1, t_vector *vct2);
t_vector		*vct_joinfree(t_vector **vct1, t_vector **vct2, int flag);
int				vct_addstr(t_vector *dest, char *src);
int				vct_addnstr(t_vector *dest, char *src, size_t size);
int				vct_pushstr(t_vector *dest, char *src);
t_vector		*vct_sub(t_vector *vct, size_t start, size_t end);
void			vct_replacechar(t_vector *vector, char to_replace, char by);
int				vct_replacestr(t_vector *vector, char *to_replace, char *by);
int				vct_apply(t_vector *vct, enum e_apply type);
int				vct_fillback(t_vector *vct, char c, size_t nb);
int				vct_fillfront(t_vector *vct, char c, size_t nb);
t_vector		*vct_splitchr(t_vector *vct, char c, int flag);
ssize_t			vct_chr(t_vector *vct, char c);
int				vct_readline(t_vector *vct, const int fd);
int				vct_creadline(t_vector *vct, const int fd, int c);
int				vct_eq(t_vector *vct1, t_vector *vct2);
int				vct_neq(t_vector *vct1, t_vector *vct2, size_t nb);
int				vct_print(t_vector *vct);
int				vct_printendl(t_vector *vct);
int				vct_print_fd(t_vector *vct, int fd);
int				vct_printendl_fd(t_vector *vct, int fd);
char			vct_getlastchar(t_vector *vct);
char			vct_getfirstchar(t_vector *vct);
char			vct_getcharat(t_vector *vct, size_t index);
int				vct_addcharat(t_vector *vct, char c, size_t index);
int				vct_addstrat(t_vector *vct, char *str, size_t index);
ssize_t			vct_str(t_vector *vct, char *str);
int				vct_startby(t_vector *vct, char *str);
int				vct_endby(t_vector *vct, char *str);
size_t			vct_countchar(t_vector *vct, char c);
size_t			vct_countstr(t_vector *vct, char *str);
int				vct_trim(t_vector *vct, char *str);
t_vector		*vct_split(t_vector *vct, char *str, uint8_t flag);
t_vector		*vct_wordsplit(t_vector *vct, char *str);
int				vct_optimize(t_vector *vct);
int				vct_fullof(t_vector *vct, char *charset);
int				vct_trimfront(t_vector *vct, char *str);
int				vct_addmemat(t_vector *vct, char *str, size_t len
					, size_t index);
int				vct_delchar(t_vector *vct, size_t index);

#endif
