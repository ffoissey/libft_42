/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:21:48 by ffoissey          #+#    #+#             */
/*   Updated: 2018/12/06 16:00:30 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "ft_string.h"
# include "ft_list.h"
# include <stdlib.h>
# include <unistd.h>
# define CLEANUP -42

typedef struct		s_file
{
	int				fd;
	int				state;
	char			*rest;
	char			*cur;
}					t_file;

int					get_next_line(const int fd, char **line);
int					get_next_line_origin(const int fd, char **line);
int					get_next_line_multifd(const int fd, char **line);

#endif
