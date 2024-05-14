/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:58:14 by shatan            #+#    #+#             */
/*   Updated: 2024/05/14 14:30:11 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_largest_idx(t_list *list, int largest_accept_val)
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
		if (cpy->head->val <= largest_accept_val && cpy->head->val > max_val)
		{
			ret = idx;
			max_val = cpy->head->val;
		}
		lst_rotate_backward(cpy);
		idx++;
	}
	lst_delete(cpy);
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

void	data_sort(t_data *data)
{
	while (lst_len(data->a) > 3)
		execute_op(data, PB);
	a_sort_3(data);
	while (lst_len(data->b) > 0)
		execute_op(data, PA);
}
