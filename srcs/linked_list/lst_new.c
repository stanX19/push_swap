#include "push_swap.h"

t_list	*lst_new(void)
{
	t_list *list;
	
	list = (t_list *)malloc(sizeof(t_list));
	if (list)
		list->head = NULL;
	return (list);
}