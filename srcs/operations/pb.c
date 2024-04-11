#include "push_swap.h"

void	pb(t_data *data)
{
	lst_push_front(data->b, lst_pop_front(data->a));
}
