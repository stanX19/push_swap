#include "push_swap.h"

void	lst_push_back(t_list *list, t_node *node)
{
	if (!list || !node)
		return ;
	lst_push_front(list, node);
	lst_rotate_backward(list);
}