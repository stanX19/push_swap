#include "push_swap.h"

void	print_list(t_list *list)
{
	t_node	*curr;

	if (!list)
	{
		ft_printf("(NULL)");
		return ;
	}
	curr = list->head;
	if (!curr)
	{
		ft_printf("[]");
		return ;
	}
	ft_printf("[");
	while (curr->next != list->head)
	{
		ft_printf("%i, ", curr->val);
		curr = curr->next;
	}
	ft_printf("%i]", curr->val);
}