#include "push_swap.h"

t_node	*lst_pop_front(t_list *list)
{
	t_node *ret;

	if (!list || !list->head)
		return (NULL);
	ret = list->head;
	if (list->head->next == list->head)
		list->head = NULL;
	else
		list->head = list->head->next;
	return(pop_node(ret));
}