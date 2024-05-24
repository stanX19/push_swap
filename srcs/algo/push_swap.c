/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:58:14 by shatan            #+#    #+#             */
/*   Updated: 2024/05/24 15:07:44 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	part1(t_data *data)
{
	int		total_len;
	int		chunk_size;
	int		threshold;
	t_list	*sorted;

	total_len = lst_len(data->a);
	chunk_size = 45;
	sorted = lst_sort_val(lst_copy(data->a));
	while (lst_len(data->a) > 3 && !lst_is_sorted(data->a))
	{
		threshold = lst_get_val(sorted, ft_min(total_len - lst_len(data->a)
					+ chunk_size, total_len - 1));
		calculate_pb_cost(data, threshold);
		pb_lowest_cost(data, true);
	}
	lst_delete(sorted);
}

void	part2(t_data *data)
{
	int	depth;

	while (lst_len(data->b) > 0)
	{
		depth = 1;//(int)(0.4 * 500.0 / (lst_len(data->b) + 90.0) + 2);
		calculate_pa_cost(data, depth, 10);
		pa_lowest_cost(data, true);
	}
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