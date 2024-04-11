#include "push_swap.h"

void	node_swap_val(t_node *n1, t_node *n2)
{
	n1->val ^= n2->val;
	n2->val ^= n1->val;
	n1->val ^= n2->val;
}