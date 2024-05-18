#include "push_swap.h"

int	norm_idx_cost(int idx, int len)
{
	if (idx > len / 2)
		return (len - idx);
	else
		return (idx);
}

int	idx_to_cost(int idx_a, int idx_b)
{
	if (ft_sign(idx_a) == ft_sign(idx_b))
	{
		return (ft_max(ft_abs(idx_a), ft_abs(idx_b)) + 1);
	}
	return (ft_abs(idx_a) + ft_abs(idx_b) + 1);
}
