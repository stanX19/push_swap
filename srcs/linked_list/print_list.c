#include "push_swap.h"

void	print_list(t_list *list)
{
	t_node	*curr;

	if (!list)
	{
		printf("(NULL)");
		return ;
	}
	curr = list->head;
	if (!curr)
		return ;
	printf("[");
	printf("%i, ", curr->val);
	curr = curr->next;
	while (curr != list->head)
	{
		printf("%i, ", curr->val);
		curr = curr->next;
	}
	printf("]");
}