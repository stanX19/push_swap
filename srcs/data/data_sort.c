/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:58:14 by shatan            #+#    #+#             */
/*   Updated: 2024/05/17 16:18:11 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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
	if (status == 3 || status == 5 || status == 6)
		exec_op_print(data, SA);
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
	int	idx_b;
	int	idx_a;

	idx_b = get_lowest_cost_idx(data->b);
	idx_a = get_largest_idx(data->a, lst_get_val(data->b, idx_b));
	if (idx_a == -1)
		idx_a = get_smallest_idx(data->a);
	else
		idx_a += 1;
	rotate_to_top(data, idx_a, idx_b, print);
	execute_op(data, PA, print);
}

int norm_idx_cost(int idx, int len)
{
	if (idx > len / 2)
		return len - idx;
	else
		return idx;
}

// cost = steps needed to push x into a + steps needed for a to be sorted
int	calculate_cost(t_data *data, int depth)
{
	int		idx_b;
	int		idx_a;
	int		ret;
	t_node	*x;

	if (depth <= 0)
		return 0;
	if (lst_len(data->b) == 0)
		return norm_idx_cost(get_smallest_idx(data->a), lst_len(data->a));
	idx_b = 0;
	ret = INT_MAX;
	while (lst_iter(data->b))
	{
		x = data->b->curr;
		idx_a = get_largest_idx(data->a, x->val - 1) + 1;
		if (idx_a == -1)
			idx_a = get_smallest_idx(data->a);
		rotate_preprocess(data, &idx_a, &idx_b);
		x->cost = 1 + ft_abs(idx_b - idx_a);
		ret = ft_min(ret, x->cost);
		idx_b++;
	}
	if (depth - 1 <= 0)
		return ret;
	t_list *b_sorted = lst_sort_cost(lst_copy(data->a));
	int max_accept;
	if (lst_len(b_sorted) >= 10)
		max_accept = lst_get_node(b_sorted, 10)->cost;
	else
		max_accept = INT_MAX;
	lst_print(b_sorted);
	lst_delete(b_sorted);
	printf("DEBUG: max_accept = %i\n", max_accept);
	ret = INT_MAX;
	while (lst_iter(data->b))
	{
		x = data->b->curr;
		if (x->cost > max_accept)
		{
			x->cost += (lst_len(data->a) + lst_len(data->b)) * (depth - 1);
			continue ;
		}
		int record = x->cost;
		x->cost = INT_MIN;
		t_data *copy = data_copy(data);
		push_lowest_cost(copy, false);
		x->cost = record + calculate_cost(copy, depth - 1);
		ret = ft_min(ret, x->cost);
		delete_data(copy);
	}
	return ret;
}

int	lst_median(t_list *list)
{
	int		ret;
	t_list	*cpy;
	
	cpy = lst_sort_val(lst_copy(list));
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
		int depth;
		depth = (double)ft_pow(500 - lst_len(data->b), 2) / 250.0 + 1;
		printf("DEBUG: depth = %i\n", depth);
		
        calculate_cost(data, depth);
        push_lowest_cost(data, true);
    }
	rotate_to_top(data, get_smallest_idx(data->a), 0, true);
}
