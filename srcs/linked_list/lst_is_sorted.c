/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_is_sorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:23:09 by shatan            #+#    #+#             */
/*   Updated: 2024/04/18 14:23:09 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	lst_is_sorted(t_list *list)
{
	t_node	*current;

	if (!list || !list->head)
		return (true);
	current = list->head;
	while (current->next != list->head)
	{
		if (current->val > current->next->val)
			return (false);
		current = current->next;
	}
	return (true);
}
