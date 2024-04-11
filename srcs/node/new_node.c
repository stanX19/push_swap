#include "push_swap.h"

t_node	*new_node(int val)
{
	t_node *node = (t_node *)malloc(sizeof(t_node));
	if (node)
	{
		node->val = val;
		node->cost = 0;
		node->next = NULL;
		node->prev = NULL;
	}
	return (node);
}