/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:58:14 by shatan            #+#    #+#             */
/*   Updated: 2024/05/02 22:29:22 by stan             ###   ########.fr       */
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

static void	rotate_to_top(t_data *data, int *target_idx, int *largest_idx, int len)
{
	int	vector;

	if (*target_idx > len / 2)
		vector = (len - *target_idx);
	else
		vector = -*target_idx;
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
	if (*largest_idx >= *target_idx)
		*largest_idx -= *target_idx;
	else
		*largest_idx = len - (*target_idx - *largest_idx);
	*target_idx = 0;
	*largest_idx %= len;
}

bool	idx_is_inorder(int idx1, int idx2, int len)
{
	return (idx1 + 1 == idx2 || (len - idx1 == 1 && idx2 == 0));
}

bool	idx_is_incident(int idx1, int idx2, int len)
{
	return (ft_abs(idx1 - idx2) == 1 || (len - idx2 == 1 && idx1 == 0));
}

static void	update_largest(t_list *a, int *target_idx, int *largest_idx)
{
	*largest_idx = *target_idx;
	*target_idx = get_largest_idx(a, lst_get_val(a, *largest_idx) - 1);
}

static void	insertion_sort(t_data *data)
{
	int	largest_idx;
	int	target_idx;

	target_idx = get_largest_idx(data->a, INT_MAX);
	while (!data_sorted(data) && target_idx >= 0)
	{
		update_largest(data->a, &target_idx, &largest_idx);
		data_print(data);
		printf("target_idx = %i; largest_idx = %i\n", target_idx, largest_idx);
		if (target_idx < 0 || idx_is_inorder(target_idx, largest_idx, lst_len(data->a)))
		{
			if (target_idx > 0)
				rra(data);
			target_idx = 0;
			continue;
		}
		// state 1
		// make target on the top
		if (target_idx == 1 && largest_idx == 0)
		{
			sa(data);
			ft_int_swap(&target_idx, &largest_idx);
			continue ;
		}
		if (idx_is_incident(target_idx, largest_idx, lst_len(data->a)))
		{
			if (largest_idx > target_idx)
				ft_int_swap(&target_idx, &largest_idx);
			rotate_to_top(data, &target_idx, &largest_idx, lst_len(data->a));
			sa(data);
			target_idx = 0;
			continue ;
		}
		rotate_to_top(data, &target_idx, &largest_idx, lst_len(data->a));
		data_print(data);
		if (data_sorted(data))
			break ;
		if (target_idx == 1 && largest_idx == 0)
		{
			sa(data);
			ft_int_swap(&target_idx, &largest_idx);
			continue ;
		}
		// state 2
		// push to b
		pb(data);
		largest_idx -= 1;
		data_print(data);
		// rotate such that prev largest is at top of a
		rotate_to_top(data, &largest_idx, &target_idx, lst_len(data->a));
		data_print(data);
		// push back to a
		pa(data);
		data_print(data);
		target_idx = 0;
	}
}

void	data_sort(t_data *data)
{
	insertion_sort(data);
}
