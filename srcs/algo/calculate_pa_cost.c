/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_pa_cost.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:20:33 by shatan            #+#    #+#             */
/*   Updated: 2024/05/25 16:22:09 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// cost = steps needed to push x into a + steps needed for a to be sorted
void	calculate_pa_cost(t_data *data, int min_accept_val)
{
	int		idx_b;
	int		idx_a;
	t_node	*x;

	while (lst_iter(data->b))
	{
		x = data->b->curr;
		if (x->val < min_accept_val)
		{
			x->cost = INT_MAX;
			continue ;
		}
		idx_b = data->b->idx;
		idx_a = get_largest_idx(data->a, x->val - 1) + 1;
		if (idx_a == 0)
			idx_a = get_smallest_idx(data->a);
		rotate_preprocess(data, &idx_a, &idx_b);
		x->cost = idx_to_cost(idx_a, idx_b);
	}
}
