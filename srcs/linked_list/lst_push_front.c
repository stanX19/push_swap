#include "push_swap.h"

void	lst_push_front(t_list *list, t_node *node)
{
	if (!list || !node)
		return ;
	if (list->head)
	{
		node->next = list->head;
		node->prev = list->head->prev;
		node->next->prev = node;
		node->prev->next = node;
	}
	else
	{
		node->next = node;
		node->prev = node;
	}
	list->head = node;
}