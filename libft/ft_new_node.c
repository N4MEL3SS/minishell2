#include "libft.h"

t_list	*ft_new_node(void *content, size_t size)
{
	t_list	*stack;
	void	*aux;

	stack = (t_list *)malloc(sizeof(t_list));
	if (!stack)
		return (NULL);
	aux = malloc(size);
	if (!aux)
		return (free(stack), NULL);
	ft_memcpy(aux, content, size);
	stack->content = aux;
	stack->next = NULL;
	return (stack);
}
