/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:58:14 by shatan            #+#    #+#             */
/*   Updated: 2024/05/29 13:16:50 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define CHUNK_SIZE 100

void	part1(t_data *data)
{
	int		total_len;
	int		threshold;
	t_list	*sorted;

	total_len = lst_len(data->a);
	sorted = lst_sort_val(lst_copy(data->a));
	while (lst_len(data->a) > 3 && !lst_is_sorted(data->a))
	{
		threshold = lst_get_val(sorted, ft_min(total_len - lst_len(data->a)
					+ CHUNK_SIZE, total_len - 1));
		calculate_pb_cost(data, threshold);
		pb_lowest_cost(data, true);
	}
	lst_delete(sorted);
}

void	part2(t_data *data)
{
	int		threshold;
	t_list	*sorted;

	sorted = lst_sort_val(lst_copy(data->b));
	while (lst_len(data->b) > 0)
	{
		threshold = INT_MIN;
		calculate_pa_cost(data, threshold);
		pa_lowest_cost(data, true);
	}
	lst_delete(sorted);
}

void	push_swap(t_data *data)
{
	if (data_is_sorted(data))
		return ;
	part1(data);
	a_sort_3(data);
	part2(data);
	rotate_to_top(data, get_smallest_idx(data->a), 0, true);
}
