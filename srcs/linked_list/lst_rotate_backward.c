#include "push_swap.h"

void	lst_rotate_backward(t_list *list)
{
	if (!list || !list->head)
		return ;
	list->head = list->head->next;
}