/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:24:24 by ffoissey          #+#    #+#             */
/*   Updated: 2019/08/29 21:47:41 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include <unistd.h>
# include "ft_list.h"
# include "ft_string.h"
# include "ft_conversion.h"
# include "ft_double.h"

# define MIN_LONG 		-9223372036854775807
# define MIN_LONG_STR	"9223372036854775808"
# define TWO_BYTES		0xc080
# define THREE_BYTES	0xe08080
# define FOUR_BYTES		0xf0808080

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

int				ft_printf(const char *format, ...);
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
