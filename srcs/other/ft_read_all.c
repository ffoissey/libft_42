/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:52:08 by ffoissey          #+#    #+#             */
/*   Updated: 2018/12/06 16:12:50 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_other.h"
#include "ft_string.h"
#include <stdlib.h>
#include <unistd.h>

char	*ft_read_all(int fd)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*str;
	char	*tmp_str;

	str = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp_str = str;
		str = ft_strjoin(str, buf);
		ft_strdel(&tmp_str);
	}
	return (ret == -1 ? NULL : str);
}
