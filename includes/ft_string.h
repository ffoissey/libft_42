/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:24:24 by ffoissey          #+#    #+#             */
/*   Updated: 2019/01/28 16:27:07 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include "define_libft.h"
# include "ft_char.h"
# include <stdlib.h>
# include <string.h>

/*
***************
**** Concat ***
***************
*/

char		*ft_strcat(char *s1, const char *s2);
char		*ft_strncat(char *s1, const char *s2, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t size);

/*
***************
****  Comp  ***
***************
*/

int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strequ(char const *s1, char const *s2);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
int			ft_strcasecmp(const char *s1, const char *s2);
int			ft_strncasecmp(const char *s1, const char *s2, size_t n);

/*
***************
**** Search ***
***************
*/

char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strcasestr(const char *haystack, const char *needle);

/*
***************
****  Copy  ***
***************
*/

char		*ft_strcpy(char *dst, const char *src);
char		*ft_strncpy(char *dst, const char *src, size_t len);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);

/*
***************
****  Dup   ***
***************
*/

char		*ft_strdup(const char *s1);
char		*ft_strndup(const char *s1, size_t n);
char		*ft_strcdup(char *s1, char c);

/*
***************
****  Join  ***
***************
*/

char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strjoinfree_n(char **s1, char **s2, int which);
char		*ft_strjoinfree(char *s1, char *s2, int which);

/*
***************
****  Sub   ***
***************
*/

char		*ft_strsub(char const *s, unsigned int start, size_t len);

/*
***************
****  Len   ***
***************
*/

size_t		ft_strlen(const char *s);
size_t		ft_strnlen(const char *s, size_t n);
size_t		ft_strclen(const char *s, char c);

/*
***************
*** Cleanup ***
***************
*/

void		ft_strclr(char *s);
void		ft_strdel(char **as);
void		ft_free_tab_str(char **tab);

/*
***************
****  Test  ***
***************
*/

int			ft_str_is_lowercase(char *str);
int			ft_str_is_uppercase(char *str);
int			ft_str_is_numeric(char *str);

/*
***************
****  New   ***
***************
*/

char		*ft_strnew(size_t size);

/*
***************
****  Trim  ***
***************
*/

char		*ft_strtrim(char const *s);
char		*ft_strctrim(char const *s, char c);

/*
***************
** Transform **
***************
*/

char		*ft_strupcase(char *str);
char		*ft_strlowcase(char *str);
char		*ft_strcapitalize(char *str);
char		*ft_strrev(char *str);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));

/*
***************
**** Split  ***
***************
*/

char		**ft_strsplit(char const *s, char c);
char		**ft_strsplit_whitespaces(char const *s);

/*
***************
****  Map   ***
***************
*/

char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

#endif
