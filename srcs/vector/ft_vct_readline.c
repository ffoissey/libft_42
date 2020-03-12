/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_readline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:13:28 by ffoissey          #+#    #+#             */
/*   Updated: 2020/03/12 15:50:28 by ffoissey         ###   ########.fr       */
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

static int	read_next(t_vector *vct, t_vector *rest, const int fd,
			int force_buffer)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;
	static int	buffer_size = -1;

	if (buffer_size == -1 && (force_buffer <= 0 || force_buffer > BUFF_SIZE))
		buffer_size = BUFF_SIZE;
	else if (buffer_size == -1)
		buffer_size = force_buffer;
	if ((ret = get_rest_til_newline(vct, rest)) == IS_EOF)
	{
		while ((ret = read(fd, buf, buffer_size)) > 0)
		{
			buf[ret] = '\0';
			if (vct_addnstr(rest, buf, ret) == FAILURE)
				return (FAILURE);
			if (vct_chr(rest, '\n') != FAILURE)
				break ;
		}
		if (ret != FAILURE)
			ret = get_rest_til_newline(vct, rest);
		if (ret == IS_EOF && vct_len(vct) > 0)
			ret = LINE_OK;
	}
	return (ret);
}

int			vct_readline(t_vector *vct, const int fd, int force_buffer)
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
			ret = read_next(vct, rest, fd, force_buffer);
			if (ret <= 0)
				vct_del(&rest);
		}
	}
	return (ret);
}
