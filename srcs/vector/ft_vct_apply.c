/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_apply.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 12:41:45 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/10 15:36:46 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

static t_int_funct		check_funct(enum e_apply type)
{
	static t_int_funct	funct[NB_INT_FT] = {ft_str_is_uppercase,
										ft_str_is_lowercase,
										ft_str_is_numeric};

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

	ret = SUCCESS;
	if (vct == NULL || vct->str == NULL || type > NB_INT_FT + NB_CHAR_PTR_FT)
		ret = FAILURE;
	else if (type < NB_INT_FT)
		ret = check_funct(type)(vct->str);
	else if (apply_funct(type - NB_INT_FT)(vct->str) == NULL)
		ret = FAILURE;
	return (ret);
}
