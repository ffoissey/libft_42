#include "ft_list.h"

#include "libft.h"

void	ft_lstdelnode(t_list **lst, void *data, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*run;

	if (lst == NULL || *lst == NULL || data == NULL)
		return ;
	run = *lst;
	if (run->content == data)
	{
		*lst = (*lst)->next;
		if (del != NULL)
			del(run->content);
		free(run);
		return ;
	}
	tmp = run;
	while (run != NULL)
	{
		if (run->content == data)
		{
			tmp->next = run->next;
			if (del != NULL)
				del(run->content);
			free(run);
			return ;
		}
		tmp = run;
		run = run->next;
	}
}
