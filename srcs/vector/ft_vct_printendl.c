/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vct_printendl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:30:59 by ffoissey          #+#    #+#             */
/*   Updated: 2019/09/13 14:31:36 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int		vct_printendl(t_vector *vct)
{
	write(STDOUT_FILENO, vct->str, vct->len);
	return (write(STDOUT_FILENO, "\n", 1));
}
