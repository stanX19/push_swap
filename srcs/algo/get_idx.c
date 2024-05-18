/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_idx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:25:59 by shatan            #+#    #+#             */
/*   Updated: 2024/05/18 14:07:46 by shatan           ###   ########.fr       */
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
