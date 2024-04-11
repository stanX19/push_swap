#include "push_swap.h"

void	lst_delete(t_list *list)
{
	t_node *current;

	if (!list || !list->head)
		return ;
	current = list->head;
	while (current->next != list->head)
	{
		t_node *temp = current;
		current = current->next;
		node_delete(temp);
	}
	node_delete(current);
	free(list);
}