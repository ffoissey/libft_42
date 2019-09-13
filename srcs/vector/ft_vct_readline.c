/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_readline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:13:28 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/13 13:44:15 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

static int	get_rest_til_newline(t_vector *vct, t_vector *rest)
{
	t_vector	*tmp;
	int			ret;

	ret = LINE_OK;
	if (vct_len(rest) != 0)
	{
		if ((tmp = vct_splitchr(rest, '\n')) != NULL)
		{
			if (vct_cat(vct, tmp) == FAILURE)
				ret = FAILURE;
			vct_del(&tmp);
		}
		else
			ret = FAILURE;
	}
	if (ret != FAILURE && vct_len(rest) == 0)
		ret = IS_EOF;
	return (ret);
}

static int	read_next(t_vector *vct, t_vector *rest, const int fd)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;

	if ((ret = get_rest_til_newline(vct, rest)) == IS_EOF)
	{
		while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
		{
			buf[ret] = '\0';
			if (vct_addnstr(rest, buf, ret) == FAILURE)
			{
				ret = FAILURE;
				break ;
			}
			if (vct_chr(rest, '\n') != (ssize_t)vct_len(rest))
				break ;
		}
		if (ret != FAILURE)
			ret = get_rest_til_newline(vct, rest);
		if (ret == IS_EOF && vct_len(vct) > 0)
			ret = LINE_OK;
	}
	return (ret);
}

int			vct_readline(t_vector *vct, const int fd)
{
	static t_vector		*rest = NULL;
	int					ret;

	ret = FAILURE;
	if (fd == CLEANUP)
	{
		ret = SUCCESS;
		vct_del(&rest);
	}
	if (fd >= 0 && vct != NULL)
	{
		vct_reset(vct, 0);
		if (rest == NULL)
			rest = vct_new(DFL_VCT_SIZE);
		if (rest != NULL)
		{
			ret = read_next(vct, rest, fd);
			if (ret <= 0)
				vct_del(&rest);
		}
	}
	return (ret);
}
