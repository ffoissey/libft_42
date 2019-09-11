/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_readline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:13:28 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/11 15:47:10 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

static ssize_t	get_rest_til_newline(t_vector *vct, t_vector *rest)
{
	t_vector	*tmp;
	if (vct_len(rest) != 0)
	{
		tmp = vct_splitchr(rest, '\n');	
		vct_cpy(vct, tmp);
		vct_del(&tmp);
	}
	return ((ssize_t)vct_len(vct));
}

static ssize_t	read_next(t_vector *vct, t_vector *rest, const int fd)
{
	ssize_t		ret;
	ssize_t		read_ret;
	char		buf[BUFF_SIZE + 1];

	ret = SUCCESS;
	if (vct_len(rest) == 0)
	{
		while ((ret = read(fd, buf, BUFF_SIZE)) != FAILURE)
		{
			buf[ret] = '\0';
			vct_addnstr(rest, buf, ret);
			if (ft_strchr(buf, '\n') != NULL || ret < BUFF_SIZE)
				break ;
		}
		read_ret = ret;
	}
	if (ret != FAILURE)
		ret = get_rest_til_newline(vct, rest);
	return (ret == 0 ? read_ret : ret);
}

ssize_t	vct_readline(t_vector *vct, const int fd)
{
	static t_vector		*rest = NULL;
	ssize_t				ret;

	ret = FAILURE;
	vct_reset(vct, DFL_VCT_SIZE);
	if (fd == CLEANUP)
	{
		ret = SUCCESS;
		vct_del(&rest);
	}
	if (fd >= 0 && vct != NULL)
	{
		if (rest == NULL)
			rest = vct_new(DFL_VCT_SIZE);
		ret = read_next(vct, rest, fd);
		if (ret == 0 || ret == FAILURE)
			vct_del(&rest);
	}
	return (ret);
}
