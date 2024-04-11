#include "push_swap.h"

void	node_swap_val_with_next(t_node *node)
{
	if (!node || !node->next || node == node->next)
		return ;
	node_swap_val(node, node->next);
}