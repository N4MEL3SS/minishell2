#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*str;

	str = malloc(sizeof(t_list));
	if (!str)
		return (NULL);
	str->content = content;
	str->next = NULL;
	return (str);
}
