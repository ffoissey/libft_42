/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_apply.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 12:41:45 by ffoissey          #+#    #+#             */
/*   Updated: 2020/04/09 16:17:06 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

static t_int_funct		check_funct(enum e_apply type)
{
	static t_int_funct	funct[NB_INT_FT] = {ft_islower, ft_isupper, ft_isalpha,
											ft_isdigit, ft_isalnum, ft_isascii,
											ft_isprint, ft_isblank, ft_iscntrl,
											ft_isgraph, ft_isspace, ft_isxdigit
											};

	return (funct[type]);
}

static t_char_ptr_funct	apply_funct(enum e_apply type)
{
	static t_char_ptr_funct	funct[NB_CHAR_PTR_FT] = {ft_strupcase,
										ft_strlowcase, ft_strcapitalize,
										ft_strrev};

	return (funct[type]);
}

int						vct_apply(t_vector *vct, enum e_apply type)
{
	int		ret;
	char	*str;

	ret = SUCCESS;
	if (vct == NULL || vct->str == NULL || type > NB_INT_FT + NB_CHAR_PTR_FT)
		ret = FAILURE;
	else if (type < NB_INT_FT)
		ret = ft_strcheck(vct->str, check_funct(type));
	else if (type == IS_NUMBER)
	{
		str = vct_getstr(vct);
		if (vct_getfirstchar(vct) == '-')
			str++;
		ret = ft_strcheck(str, check_funct(IS_DIGIT));
	}
	else if (apply_funct(type - NB_INT_FT)(vct->str) == NULL)
		ret = FAILURE;
	return (ret);
}
