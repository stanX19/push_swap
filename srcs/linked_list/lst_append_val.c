#include "push_swap.h"

void	lst_append_val(t_list *list, int val)
{
	lst_push_back(list, new_node(val));
}