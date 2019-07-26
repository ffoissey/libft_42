/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:25:10 by ffoissey          #+#    #+#             */
/*   Updated: 2019/07/26 09:37:29 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include "define_libft.h"
# include "ft_memory.h"
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
***************
****  New  ****
***************
*/

t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstnew_nomalloc(void *content, size_t content_size);

/*
***************
****  Add  ****
***************
*/

void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstadd_back(t_list **alst, t_list *new);

/*
***************
****  Del  ****
***************
*/

void				ft_lstpop(t_list **alst);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelnode(t_list **lst, void *data,
						void (*del)(void *));

/*
***************
****  Map  ****
***************
*/

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
***************
****  Get  ****
***************
*/

t_list				*ft_lstlast(t_list *lst);
int					ft_lstsize(t_list *lst);

/*
***************
**** Sort  ****
***************
*/

void				ft_lst_mergesort(t_list **lst, int (*test)(void *, void *));

#endif
