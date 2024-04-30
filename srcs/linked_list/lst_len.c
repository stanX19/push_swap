#include "push_swap.h"

size_t	lst_len(t_list *list)
{
	t_node *curr;
	size_t ret;

	if (!list || !list->head)
		return (0);
	curr = list->head;
	ret = 1;
	while (curr->next != list->head)
	{
		curr = curr->next;
		ret++;
	}
	return (ret);
}
