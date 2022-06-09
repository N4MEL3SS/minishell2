#include "libft.h"

void	ft_lst_swap(t_list *list)
{
	void	*content;

	content = list->content;
	list->content = list->next->content;
	list->next->content = content;
}

void	ft_lst_sort(t_list **lst, int (*cmp)())
{
	t_list	*a;
	t_list	*b;

	a = *lst;
	while (a != NULL)
	{
		b = *lst;
		while (b->next != NULL)
		{
			if ((*cmp)(b->content, b->next->content) > 0)
				ft_lst_swap(b);
			b = b->next;
		}
		a = a->next;
	}
}
