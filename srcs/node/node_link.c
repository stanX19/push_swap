#include "push_swap.h"

void node_link(t_node *prev, t_node* next)
{
	prev->next = next;
	next->prev = prev;
}