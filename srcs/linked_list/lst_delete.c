/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:19:05 by shatan            #+#    #+#             */
/*   Updated: 2024/04/18 14:21:15 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_delete(t_list *list)
{
	t_node	*current;

	if (!list)
		return ;
	if (list->head)
	{
		current = list->head;
		while (current->next != list->head)
		{
			current = current->next;
			node_delete(current->prev);
		}
		node_delete(current);
	}
	free(list);
}
