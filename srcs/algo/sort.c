/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:58:14 by shatan            #+#    #+#             */
/*   Updated: 2024/05/18 13:48:12 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	push_swap(t_data *data)
{
	int		total_len;
	t_list	*sorted;
	int		threshold;

	if (data_is_sorted(data))
		return ;
	total_len = lst_len(data->a);
	sorted = lst_sort_val(lst_copy(data->a));
	while (lst_len(data->a) > 3)
	{
		threshold = lst_get_val(sorted, ft_min(total_len - lst_len(data->a)
					+ (total_len / 11), total_len - 1));
		if (lst_get_val(data->a, 0) <= threshold)
			exec_op_print(data, PB);
		else
			exec_op_print(data, RA);
	}
	lst_delete(sorted);
	a_sort_3(data);
	while (lst_len(data->b) > 0)
	{
		calculate_cost(data, 3, 10);
		push_lowest_cost(data, true);
	}
	rotate_to_top(data, get_smallest_idx(data->a), 0, true);
}
