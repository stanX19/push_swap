/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:33:02 by stan              #+#    #+#             */
/*   Updated: 2024/05/15 20:21:36 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lst_sort(t_list *list)
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
				node_swap_val_with_next(curr);
			curr = curr->next;
		}
		counter = counter->next;
	}
	return (list);
}
