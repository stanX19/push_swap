/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:58:14 by shatan            #+#    #+#             */
/*   Updated: 2024/04/30 17:00:53 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_largest(t_list *list, int reject_val)
{
	t_list	*cpy;
	int		ret;
	int		idx;
	int		len;
	int		max_val;

	cpy = lst_copy(list);
	ret = 0;
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
	if (ret > len / 2)
		ret = ret - len;
	return ret;
}

static void rotate(t_data *data, int vector)
{
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

static void	insertion_sort(t_data *data)
{
	int largest;
	int largest_idx;
	int len;
	int state;

	len = lst_len(data->a);
	largest_idx = get_largest(data->a, INT_MAX);
	largest = lst_get_val(data->a, largest_idx);
	printf("largest = %i\n", largest);
	state = 0;
	while (!data_sorted(data))
	{
		if (state == 0)
		{
			int target_idx = get_largest(data->a, largest - 1);
			int shift = -target_idx;
			
			printf("shift = %i\n", shift);
			printf("target_idx = %i\n", target_idx);
			
			// state 1
			// make target on the top
			rotate(data, shift);
			target_idx += shift;
			largest_idx += shift;
			
			// force largest idx to be positive
			while (largest_idx < 0)
				largest_idx += len;
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
			rotate(data, -largest_idx);
			data_print(data);
			
			// push back to a
			pa(data);
			data_print(data);

			// overwrite largest data, repeat
			largest_idx = 0;
			largest = lst_get_val(data->a, 0);
			printf("largest = %i\n", largest);
			
			data_print(data);
			state = 0;
		}
	}
	
}

void	data_sort(t_data *data)
{
	insertion_sort(data);
}
