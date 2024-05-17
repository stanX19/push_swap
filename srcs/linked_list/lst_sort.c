/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:33:02 by stan              #+#    #+#             */
/*   Updated: 2024/05/17 15:19:30 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lst_sort_val(t_list *list)
{
	t_node	*curr;
	t_node	*counter;

	if (!list || !list->head)
		return (list);
	counter = list->head;
	while (counter->next != list->head)
	{
		curr = list->head;
		while (curr->next != list->head)
		{
			if (curr->val > curr->next->val)
				node_swap_with_next(curr);
			curr = curr->next;
		}
		counter = counter->next;
	}
	return (list);
}

t_list	*lst_sort_cost(t_list *list)
{
	t_node	*curr;
	t_node	*counter;

	if (!list || !list->head)
		return (list);
	counter = list->head;
	while (counter->next != list->head)
	{
		curr = list->head;
		while (curr->next != list->head)
		{
			if (curr->cost > curr->next->cost)
				node_swap_with_next(curr);
			curr = curr->next;
		}
		counter = counter->next;
	}
	return (list);
}
