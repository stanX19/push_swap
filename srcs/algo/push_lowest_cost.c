#include "push_swap.h"

void	push_lowest_cost(t_data *data, bool print)
{
	int	idx_b;
	int	idx_a;

	idx_b = get_lowest_cost_idx(data->b);
	idx_a = get_largest_idx(data->a, lst_get_val(data->b, idx_b));
	if (idx_a == -1)
		idx_a = get_smallest_idx(data->a);
	else
		idx_a += 1;
	rotate_to_top(data, idx_a, idx_b, print);
	execute_op(data, PA, print);
}
