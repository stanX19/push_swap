/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:58:14 by shatan            #+#    #+#             */
/*   Updated: 2024/05/16 12:42:59 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_largest_idx(t_list *list, int max_accept)
{
	int	ret;
	int	idx;
	int	max_val;

	ret = -1;
	idx = 0;
	max_val = INT_MIN;
	while (lst_iter(list))
	{
		if (list->curr->val <= max_accept && list->curr->val > max_val)
		{
			ret = idx;
			max_val = list->curr->val;
		}
		idx++;
	}
	return (ret);
}
int	get_smallest_idx(t_list *list)
{
	int	ret;
	int	idx;
	int	min_val;

	ret = -1;
	idx = 0;
	min_val = INT_MAX;
	while (lst_iter(list))
	{
		if (list->curr->val < min_val)
		{
			ret = idx;
			min_val = list->curr->val;
		}
		idx++;
	}
	return (ret);
}
int	get_lowest_cost_idx(t_list *list)
{
	int	ret;
	int	idx;
	int	min_val;

	ret = -1;
	idx = 0;
	min_val = INT_MAX;
	while (lst_iter(list))
	{
		if (list->curr->cost < min_val)
		{
			ret = idx;
			min_val = list->curr->cost;
		}
		idx++;
	}
	return (ret);
}

int	get_status(t_list *list)
{
	t_node	*curr;
	int		status;
	int		bit;

	curr = list->head;
	status = 0;
	bit = 1;
	while (curr->prev != list->head)
	{
		status += bit * (curr->prev->val > curr->val);
		bit <<= 1;
		curr = curr->prev;
	}
	status += bit * (curr->prev->val > curr->val);
	return (status);
}

void	a_sort_3(t_data *data)
{
	int	status;

	status = get_status(data->a);
	if (status == 2)
		exec_op_print(data, RRA);
	else if (status == 3)
		exec_op_print(exec_op_print(data, SA), RA);
	else if (status == 4)
		exec_op_print(data, RA);
	else if (status == 5)
		exec_op_print(data, SA);
	else if (status == 6)
		exec_op_print(exec_op_print(data, SA), RRA);
}

void	rotate_preprocess(t_data *data, int *idx_a, int *idx_b)
{
	int	len_a;
	int	len_b;

	len_a = lst_len(data->a);
	len_b = lst_len(data->b);
	if (len_a)
		*idx_a %= len_a;
	if (len_b)
		*idx_b %= len_b;
	if (*idx_a > len_a / 2)
		*idx_a -= len_a;
	if (*idx_b > len_b / 2)
		*idx_b -= len_b;
}

static void	rotate_positive(t_data *data, int *idx_a, int *idx_b, bool print)
{
	while (*idx_b > 0 && *idx_a > 0)
	{
		execute_op(data, RR, print);
		(*idx_b)--;
		(*idx_a)--;
	}
	while (*idx_b > 0)
	{
		execute_op(data, RB, print);
		(*idx_b)--;
	}
	while (*idx_a > 0)
	{
		execute_op(data, RA, print);
		(*idx_a)--;
	}
}

static void	rotate_negative(t_data *data, int *idx_a, int *idx_b, bool print)
{
	while (*idx_b < 0 && *idx_a < 0)
	{
		execute_op(data, RRR, print);
		(*idx_b)++;
		(*idx_a)++;
	}
	while (*idx_b < 0)
	{
		execute_op(data, RRB, print);
		(*idx_b)++;
	}
	while (*idx_a < 0)
	{
		execute_op(data, RRA, print);
		(*idx_a)++;
	}
}
void	rotate_to_top(t_data *data, int idx_a, int idx_b, bool print)
{
	rotate_preprocess(data, &idx_a, &idx_b);
	rotate_positive(data, &idx_a, &idx_b, print);
	rotate_negative(data, &idx_a, &idx_b, print);
}

void	push_lowest_cost(t_data *data, bool print)
{
	int	lowest_cost_idx;
	int	target_a_idx;

	lowest_cost_idx = get_lowest_cost_idx(data->b);
	target_a_idx = get_largest_idx(data->a, lst_get_val(data->b,
				lowest_cost_idx));
	rotate_to_top(data, target_a_idx + 1, lowest_cost_idx, print);
	execute_op(data, PA, print);
}

// cost = steps needed to push x into a + steps needed for a to be sorted
int	calculate_cost(t_data *data, int depth)
{
	int		idx_b;
	int		idx_a;
	int		ret;
	t_node	*x;

	if (depth <= 0 || lst_len(data->b) == 0)
		return 0;
	idx_b = 0;
	ret = INT_MAX;
	while (lst_iter(data->b))
	{
		x = data->b->curr;
		idx_a = get_largest_idx(data->a, x->val - 1) + 1;
		rotate_preprocess(data, &idx_a, &idx_b);
		x->cost = INT_MIN;
		if (depth - 1 > 0)
		{
			t_data *copy = data_copy(data);
			push_lowest_cost(copy, false);
			x->cost = 1 + ft_abs(idx_b - idx_a) + calculate_cost(copy, depth - 1);
			delete_data(copy);
		}
		else
			x->cost = 1 + ft_abs(idx_b - idx_a);
		ret = ft_min(ret, x->cost);
		idx_b++;
	}
	return ret;
}

int	lst_median(t_list *list)
{
	int		ret;
	t_list	*cpy;
	
	cpy = lst_sort(lst_copy(list));
	ret = lst_get_val(cpy, lst_len(cpy) / 2);
	lst_delete(cpy);
	return (ret);
}

void	data_sort(t_data *data)
{
	if (data_is_sorted(data))
		return ;
	while (lst_len(data->a) > 3)
	{	
		if (lst_get_val(data->a, 0) < lst_median(data->a))
			exec_op_print(data, PB);
		else
			exec_op_print(data, RA);
	}
	a_sort_3(data);
	while (lst_len(data->b) > 0)
	{
		calculate_cost(data, 100);
		push_lowest_cost(data, true);
	}
	rotate_to_top(data, get_smallest_idx(data->a), 0, true);
}
