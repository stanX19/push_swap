/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:58:14 by shatan            #+#    #+#             */
/*   Updated: 2024/05/02 20:07:16 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_largest_idx(t_list *list, int reject_val)
{
	t_list	*cpy;
	int		ret;
	int		idx;
	int		len;
	int		max_val;

	cpy = lst_copy(list);
	ret = -1;
	idx = 0;
	len = lst_len(cpy);
	max_val = 0;
	while (idx < len)
	{
		if (cpy->head->val <= reject_val && cpy->head->val > max_val)
		{
			ret = idx;
			max_val = cpy->head->val;
		}
		lst_rotate_backward(cpy);
		idx++;
	}
	lst_delete(cpy);
	// if (ret > len / 2)
	// 	ret = ret - len;
	return (ret);
}

static void	rotate_to_top(t_data *data, int idx, int len)
{
	int	vector;

	if (idx > len / 2)
		vector = (len - idx);
	else
		vector = -idx;
	while (vector > 0)
	{
		rra(data);
		vector--;
	}
	while (vector < 0)
	{
		ra(data);
		vector++;
	}
}

static void	update_largest(t_list *a, int *target_idx, int *largest,
		int *largest_idx)
{
	if (*target_idx < 0)
		return ;
	if (*target_idx + 1 != *largest_idx && !(lst_len(a) - *target_idx == 1
			&& *largest_idx == 0))
		return ;
	*largest_idx = *target_idx;
	*largest = lst_get_val(a, *largest_idx);
	*target_idx = get_largest_idx(a, *largest - 1);
	update_largest(a, target_idx, largest, largest_idx);
}

static void	insertion_sort(t_data *data)
{
	int	largest;
	int	largest_idx;
	int	len;
	int	state;
	int	target_idx;

	len = lst_len(data->a);
	largest_idx = get_largest_idx(data->a, INT_MAX);
	largest = lst_get_val(data->a, largest_idx);
	printf("largest = %i\n", largest);
	state = 0;
	while (!data_sorted(data))
	{
		if (state == 0)
		{
			target_idx = get_largest_idx(data->a, largest - 1);
			update_largest(data->a, &target_idx, &largest, &largest_idx);
			if (target_idx < 0)
			{
				target_idx = largest_idx;
			}
			printf("target_idx = %i\n", target_idx);
			// state 1
			// make target on the top
			rotate_to_top(data, target_idx, len);
			if (largest_idx >= target_idx)
				largest_idx -= target_idx;
			else
				largest_idx = len - (target_idx - largest_idx);
			target_idx = 0;
			largest_idx %= len;
			// force largest idx to be positive
			// while (largest_idx < 0)
			// 	largest_idx += len;
			data_print(data);
			state = 1;
		}
		else if (state == 1)
		{
			// state 2
			// push to b
			pb(data);
			largest_idx -= 1;
			data_print(data);
			// rotate such that prev largest is at top of a
			rotate_to_top(data, largest_idx, len - 1);
			data_print(data);
			// push back to a
			pa(data);
			data_print(data);
			// overwrite largest data, repeat
			largest_idx = 0;
			largest = lst_get_val(data->a, 0);
			state = 0;
		}
	}
}

void	data_sort(t_data *data)
{
	insertion_sort(data);
}
