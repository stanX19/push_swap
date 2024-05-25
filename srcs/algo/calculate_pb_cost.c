/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_pb_cost.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:20:33 by shatan            #+#    #+#             */
/*   Updated: 2024/05/25 16:09:36 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// cost = steps needed to push x into a + steps needed for a to be sorted
void	calculate_pb_cost(t_data *data, int max_accept_val)
{
	int		len_a;
	int		idx_a;
	t_node	*x;

	len_a = lst_len(data->a);
	idx_a = 0;
	while (lst_iter(data->a))
	{
		x = data->a->curr;
		if (x->val <= max_accept_val)
			x->cost = norm_idx_cost(idx_a, len_a);
		else
			x->cost = INT_MAX;
		idx_a++;
	}
}
