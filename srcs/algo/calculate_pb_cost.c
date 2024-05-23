/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_pb_cost.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:20:33 by shatan            #+#    #+#             */
/*   Updated: 2024/05/23 23:23:03 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// cost = steps needed to push x into a + steps needed for a to be sorted
int	calculate_pb_cost(t_data *data, int max_accept_val)
{
	int		len_a;
	int		idx_a;
	int		min_cost;
	t_node	*x;

	len_a = lst_len(data->a);
	if (len_a == 0)
		return 0;
	idx_a = 0;
	min_cost = INT_MAX;
	while (lst_iter(data->a))
	{
		x = data->a->curr;
		if (x->val <= max_accept_val)
			x->cost = norm_idx_cost(idx_a, len_a);
		else
			x->cost = INT_MAX;
		min_cost = ft_min(min_cost, x->cost);
		idx_a++;
	}
	return (min_cost);
}
