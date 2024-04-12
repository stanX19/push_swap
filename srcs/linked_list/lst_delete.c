#include "push_swap.h"

void	lst_delete(t_list *list)
{
	t_node *current;

	if (!list)
		return ;
	if (list->head)
	{
		current = list->head;
		while (current->next != list->head)
		{
			current = current->next;
			node_delete(current->prev);
		}
		node_delete(current);
	}
	free(list);
}