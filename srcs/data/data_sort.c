/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:58:14 by shatan            #+#    #+#             */
/*   Updated: 2024/05/14 19:15:46 by stan             ###   ########.fr       */
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
		execute_op(data, RRA);
	else if (status == 3)
		execute_op(execute_op(data, SA), RA);
	else if (status == 4)
		execute_op(data, RA);
	else if (status == 5)
		execute_op(data, SA);
	else if (status == 6)
		execute_op(execute_op(data, SA), RRA);
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

static void	rotate_positive(t_data *data, int *idx_a, int *idx_b)
{
	while (*idx_b > 0 && *idx_a > 0)
	{
		execute_op(data, RR);
		(*idx_b)--;
		(*idx_a)--;
	}
	while (*idx_b > 0)
	{
		execute_op(data, RB);
		(*idx_b)--;
	}
	while (*idx_a > 0)
	{
		execute_op(data, RA);
		(*idx_a)--;
	}
}

static void	rotate_negative(t_data *data, int *idx_a, int *idx_b)
{
	while (*idx_b < 0 && *idx_a < 0)
	{
		execute_op(data, RRR);
		(*idx_b)++;
		(*idx_a)++;
	}
	while (*idx_b < 0)
	{
		execute_op(data, RRB);
		(*idx_b)++;
	}
	while (*idx_a < 0)
	{
		execute_op(data, RRA);
		(*idx_a)++;
	}
}
void	rotate_to_top(t_data *data, int idx_a, int idx_b)
{
	rotate_preprocess(data, &idx_a, &idx_b);
	rotate_positive(data, &idx_a, &idx_b);
	rotate_negative(data, &idx_a, &idx_b);
}

// cost = steps needed to push x into a + steps needed for a to be sorted
void	calculate_cost(t_data *data)
{
	int		idx_b;
	int		idx_a;
	t_node	*x;

	idx_b = 0;
	while (lst_iter(data->b))
	{
		x = data->b->curr;
		idx_a = get_largest_idx(data->a, x->val - 1) + 1;
		rotate_preprocess(data, &idx_a, &idx_b);
		x->cost = 1 + ft_abs(idx_b - idx_a);
		idx_b++;
	}
}

void	push_lowest_cost(t_data *data)
{
	int	lowest_cost_idx;
	int	target_a_idx;

	lowest_cost_idx = get_lowest_cost_idx(data->b);
	target_a_idx = get_largest_idx(data->a, lst_get_val(data->b,
				lowest_cost_idx));
	rotate_to_top(data, target_a_idx + 1, lowest_cost_idx);
	execute_op(data, PA);
}

void	data_sort(t_data *data)
{
	if (data_is_sorted(data))
		return ;
	while (lst_len(data->a) > 3)
		execute_op(data, PB);
	a_sort_3(data);
	while (lst_len(data->b) > 0)
	{
		calculate_cost(data);
		push_lowest_cost(data);
	}
	rotate_to_top(data, get_smallest_idx(data->a), 0);
}
