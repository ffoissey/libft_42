/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:24:24 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/07 20:54:26 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include <unistd.h>
# include "ft_list.h"
# include "ft_vector.h"
# include "ft_string.h"
# include "ft_conversion.h"
# include "ft_double.h"

# define MIN_LONG 		LONG_MIN
# define MIN_LONG_STR	#LONG_MIN
# define TWO_BYTES		0xc080
# define THREE_BYTES	0xe08080
# define FOUR_BYTES		0xf0808080


# define NO_FLAG				0x0000000000000000

/*
**** MODIFIERS
*/

# define MOD_HH					0x0000000000000001
# define MOD_LL					0x0000000000000002
# define MOD_H					0x0000000000000004
# define MOD_L					0x0000000000000008
# define MOD_L_MAJ				0x0000000000000010

/*
**** FLAGS
*/

# define FLAG_HASH				0x0000000000000020
# define FLAG_ZERO				0x0000000000000040
# define FLAG_MIN				0x0000000000000080
# define FLAG_PLUS				0x0000000000000010
# define FLAG_SPACE				0x0000000000000020
# define FLAG_DOT				0x0000000000000040
# define FLAG_FIELD				0x0000000000000080
# define FLAG_NONE				0x0000000000000100

/*
**** CONVERSIONS
*/

# define CONV_WILDCARD			0x0000000001000000
# define CONV_C					0x0000000002000000
# define CONV_C_MAJ				0x0000000004000000
# define CONV_S					0x0000000008000000
# define CONV_S_MAJ				0x0000000010000000
# define CONV_P					0x0000000020000000
# define CONV_B					0x0000000040000000
# define CONV_B_MAJ				0x0000000080000000
# define CONV_D					0x0000000100000000
# define CONV_D_MAJ				0x0000000200000000
# define CONV_I					0x0000000400000000
# define CONV_O					0x0000000800000000
# define CONV_O_MAJ				0x0000001000000000
# define CONV_U					0x0000002000000000
# define CONV_U_MAJ				0x0000004000000000
# define CONV_X					0x0000008000000000
# define CONV_X_MAJ				0x0000010000000000
# define CONV_F					0x0000020000000000
# define CONV_F_MAJ				0x0000040000000000
# define CONV_PERCENT			0x0000080000000000
# define CONV_NONE				0x0000100000000000

# define NB_FLAG				11
# define NB_CONV				20
# define PRECISION_FLAG			10
# define CONV_SCALE				0x1000000
# define ALL_MOD				0x3f

# define FORMAT_CHAR			'%'

enum e_state
{
	STATE_STRING,
	STATE_FLAG,
	STATE_CONV,
	STATE_FINISH
};

typedef	struct		s_option
{
	uint64_t		flag;
	uint64_t		precision;
	uint64_t		field;
}					t_option;

typedef	struct		s_machine
{
	t_option		option;
	enum e_state	state;
}					t_machine;

typedef	struct	s_flag
{
	char		*str;

	int			sharp;
	int			zero;
	int			min;
	int			plus;
	int			l_low;
	int			l_up;
	int			ll;
	int			h;
	int			hh;
	int			dot;
	int			space;
	int			precision;
	int			field;
	int			neg;
	int			percent;
	int			null;
	int			wildcard;
}				t_flag;

typedef	int64_t		(*t_func_machine)(t_machine *, char *, t_vector *, va_list *);
typedef	t_vector	*(*t_func_conv)(va_list *, t_option *);

int				ft_printf(const char *format, ...);

t_vector		*di_conv(va_list *arg, t_option *option);






int				ft_dprintf(int fd, const char *format, ...);
char			*ft_asprintf(const char *format, ...);
int				ft_loop_args(char *s, va_list *args, char **out, t_flag *flag);
char			*ft_fillcstr(const char *s, char **out, int null);
void			ft_wildcard(va_list *args, t_flag *flag);
double			ft_double_select(va_list *args, t_flag *flag);
char			*ft_nb(va_list *args, char *format, t_flag *flag);
char			*ft_set_all_flags(char *s, t_flag *flag);
void			ft_init_flags(t_flag *flag);
char			*ft_itoa_base_l(long long value, int base);
char			*ft_itoa_base_lu(unsigned long long value,
					unsigned int base);
char			*ft_hub_conversion_nb(long long nb, t_flag *flag, char c);
char			*ft_conversion_char(int c, t_flag *flag);
char			*ft_conversion_str(const char *src, t_flag *flag);
char			*ft_conversion_double(long double nb, t_flag *flag, char c);
void			ft_filler(char **s, char *add, int after, int null);
void			ft_join_free(char **s, char const *new, int after, int null);
int				ft_check_flag(t_flag *flag);
char			*ft_error_flag(char *s, t_flag *flag);
void			ft_fill_string(char **s, t_flag *flag, char c);
char			*ft_strjoin_hub(const char *s1, const char *s2,
				int null, int id);
char			*ft_strjoin_null(const char *s1, const char *s2,
				int null, int id);
size_t			ft_strlen_null(const char *s, int null);
char			*ft_conversion_u(unsigned long long nb, t_flag *flag,
				char c);
char			*ft_strnew_c(size_t size, char c);
char			*ft_bad_flag(char *s, t_flag *flag);
char			*ft_dtoa(void *ptr, int prec);
void			ft_set_wildcard(t_flag *flag);
void			ft_set_min_field_size(char **s, t_flag *flag);
void			ft_set_precision(char **s, t_flag *flag);
void			ft_set_attribute_flags(char **s, t_flag *flag);
void			ft_set_length_flags(char **s, t_flag *flag);
int				ft_conversion_lstr(wchar_t *src, t_flag *flag, char **new);
int				ft_conversion_lchar(wint_t c, t_flag *flag, char **new);
int				ft_ok_conv(char c);
int				ft_ok_dioux(char c);
int				ft_ret_largechar(unsigned int c);
int				ft_check_largechar(unsigned int c, char **to_free);
void			ft_nan_inf(char *s, t_flag *flag);
void			ft_double_flag_neg(char **s, t_flag *flag);

#endif
