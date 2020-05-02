/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_creadline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:13:28 by ffoissey          #+#    #+#             */
/*   Updated: 2020/05/01 14:26:06 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

static int	read_next(t_vector *vct, t_vector *rest, const int fd, int c)
{
	char		buf[BUFF_SIZE];
	t_vector	*line;
	ssize_t		ret;

	ret = LINE_OK;
	if (vct_chr(rest, c) == FAILURE)
	{
		while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
		{
			if (vct_addnstr(rest, buf, (size_t)ret) == FAILURE)
				return (FAILURE);
			if (vct_chr(rest, c) != FAILURE)
				break ;
		}
		if (ret == FAILURE)
			return (FAILURE);
	}
	line = vct_splitchr(rest, c, DEL_CHAR);
	if (vct_cpy(vct, line) == FAILURE)
		ret = FAILURE;
	if (ret == IS_EOF && vct_len(vct) > 0)
		ret = LINE_OK;
	vct_del(&line);
	return ((int)ret);
}

int			vct_creadline(t_vector *vct, const int fd, int c)
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
			ret = read_next(vct, rest, fd, c);
			if (ret <= 0)
				vct_del(&rest);
		}
	}
	return (ret);
}
