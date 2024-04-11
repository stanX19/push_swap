#include "push_swap.h"

void	pa(t_data *data)
{
	lst_push_front(data->a, lst_pop_front(data->b));
}