/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:50:16 by ffoissey          #+#    #+#             */
/*   Updated: 2018/11/29 15:51:38 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*init_new_file(const int fd, char **line)
{
	t_file			*file;
	t_list			*new_list;

	if (fd < 0 || !line)
		return (NULL);
	if (!(file = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	file->fd = fd;
	file->rest = NULL;
	file->cur = NULL;
	file->state = -1;
	if (!(new_list = ft_lstnew(file, sizeof(t_file))))
	{
		free(file);
		file = NULL;
		if (new_list)
		{
			free(new_list);
			new_list = NULL;
		}
		return (NULL);
	}
	free(file);
	file = NULL;
	return (new_list);
}

static void		ft_fill_line_with_rest(t_file *file)
{
	char	*tmp;
	char	*tmp_rest;

	file->state = 0;
	if (file->rest)
	{
		if ((!(tmp = ft_strchr(file->rest, '\n'))) || (tmp && !*(tmp + 1)))
		{
			file->cur = ft_strdup(file->rest);
			if (tmp && !*(tmp + 1))
			{
				file->cur[ft_strlen(file->rest) - 1] = '\0';
				file->state = 1;
			}
			ft_strdel(&(file->rest));
		}
		else
		{
			file->cur = ft_strsub(file->rest, 0, tmp - file->rest);
			tmp_rest = file->rest;
			file->rest = ft_strdup(tmp + 1);
			ft_strdel(&tmp_rest);
			file->state = 1;
		}
	}
}

static int		ft_read(t_file *file)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	char	*tmp_cur;

	while ((ret = read(file->fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp_cur = file->cur;
		if ((tmp = ft_strchr(buf, '\n')))
		{
			file->state = 1;
			if (*(tmp + 1))
				file->rest = ft_strdup(tmp + 1);
			buf[tmp - buf] = '\0';
			file->cur = ft_strjoin(file->cur, buf);
			ft_strdel(&tmp_cur);
			return (0);
		}
		file->cur = ft_strjoin(file->cur, buf);
		ft_strdel(&tmp_cur);
	}
	if (file->cur && file->cur[0] != '\0')
		file->state = 1;
	return (ret == -1 ? -1 : file->state);
}

static void		free_cp_lst(t_list **lst, t_file *file, char **line)
{
	if (file->cur)
	{
		*line = ft_strdup(file->cur);
		ft_strdel(&file->cur);
	}
	else
	{
		free(file);
		file = NULL;
		free(*lst);
		*lst = NULL;
	}
}

int				get_next_line(const int fd, char **line)
{
	static	t_list	*lst = NULL;
	t_list			*tmp;

	if (!line || (!lst && !(lst = init_new_file(fd, line))))
		return (-1);
	tmp = lst;
	while (tmp)
	{
		if (FILEL->fd == fd)
		{
			ft_fill_line_with_rest(FILEL);
			if (FILEL->state != 1 && ft_read(FILEL) == -1)
				return (-1);
			break ;
		}
		if (!tmp->next && !(tmp->next = init_new_file(fd, line)))
			return (-1);
		tmp = tmp->next;
	}
	free_cp_lst(&tmp, FILEL, line);
	return (tmp ? FILEL->state : 0);
}
