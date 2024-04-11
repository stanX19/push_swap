#include "push_swap.h"

/*************************************\
	src           src_curr
	cpy cpy_curr
\*************************************/
t_list	*lst_copy(t_list *list)
{
	t_list *copy;
	t_node *src_curr;

	if (!list)
		return (NULL);
	copy = lst_new();
	if (!list->head)
		return copy;
	src_curr = list->head;
	lst_append_val(copy, src_curr->val);
	src_curr = src_curr->next;
	while (src_curr != list->head)
	{
		lst_append_val(copy, src_curr->val);
		src_curr = src_curr->next;
	}
	return (copy);
}