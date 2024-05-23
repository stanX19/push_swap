/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_pa_cost.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:20:33 by shatan            #+#    #+#             */
/*   Updated: 2024/05/23 23:22:23 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	propagate_subtree(t_data *data, t_node *x, int depth, size_t max_branch)
{
	int		original_cost;
	t_data	*copy;

	original_cost = x->cost;
	x->cost = INT_MIN;
	copy = data_copy(data);
	pa_lowest_cost(copy, false);
	x->cost = original_cost + calculate_pa_cost(copy, depth - 1, max_branch);
	delete_data(copy);
	return (x->cost);
}

static int	propagate(t_data *data, int depth, size_t max_branch)
{
	t_list	*sorted_b;
	int		max_accept_cost;
	int		min_cost;
	t_node	*x;

	sorted_b = lst_sort_cost(lst_copy(data->b));
	if (lst_len(sorted_b) > max_branch)
		max_accept_cost = lst_get_node(sorted_b, max_branch)->cost;
	else
		max_accept_cost = INT_MAX;
	lst_delete(sorted_b);
	min_cost = INT_MAX;
	while (lst_iter(data->b))
	{
		x = data->b->curr;
		if (x->cost > max_accept_cost)
		{
			x->cost = INT_MAX;
			continue ;
		}
		min_cost = ft_min(min_cost, propagate_subtree(data, x, depth,
					max_branch));
	}
	return (min_cost);
}

// cost = steps needed to push x into a + steps needed for a to be sorted
int	calculate_pa_cost(t_data *data, int depth, size_t max_branch)
{
	int		idx_b;
	int		idx_a;
	int		min_cost;
	t_node	*x;

	if (depth <= 0)
		return (0);
	if (lst_len(data->b) == 0)
		return (norm_idx_cost(get_smallest_idx(data->a), lst_len(data->a)));
	idx_b = 0;
	min_cost = INT_MAX;
	while (lst_iter(data->b))
	{
		x = data->b->curr;
		idx_a = get_largest_idx(data->a, x->val - 1) + 1;
		if (idx_a == -1)
			idx_a = get_smallest_idx(data->a);
		rotate_preprocess(data, &idx_a, &idx_b);
		x->cost = idx_to_cost(idx_a, idx_b);
		min_cost = ft_min(min_cost, x->cost);
		idx_b++;
	}
	if (depth - 1 <= 0)
		return (min_cost);
	return (propagate(data, depth, max_branch));
}
