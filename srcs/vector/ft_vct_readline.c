/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_readline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:13:28 by ffoissey          #+#    #+#             */
/*   Updated: 2020/04/11 16:30:05 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

static int	read_next(t_vector *vct, t_vector *rest, const int fd)
{
	char		buf[BUFF_SIZE];
	t_vector	*line;
	int			ret;

	ret = LINE_OK;
	if (vct_chr(rest, '\n') == FAILURE)
	{
		while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
		{
			if (vct_addnstr(rest, buf, ret) == FAILURE)
				return (FAILURE);
			if (vct_chr(rest, '\n') != FAILURE)
				break ;
		}
		if (ret == FAILURE)
			return (FAILURE);
	}
	line = vct_splitchr(rest, '\n', DEL_CHAR);
	if (vct_cpy(vct, line) == FAILURE)
		ret = FAILURE;
	if (ret == IS_EOF && vct_len(vct) > 0)
		ret = LINE_OK;
	vct_del(&line);
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
