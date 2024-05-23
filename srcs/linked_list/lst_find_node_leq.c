/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_find_node_leq.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:06:02 by shatan            #+#    #+#             */
/*   Updated: 2024/05/23 23:03:50 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*lst_find_first_leq(t_list *lst, int val)
{
	t_node	*curr;

	curr = lst->head;
	if (!curr)
		return (NULL);
	if (curr->val > val)
		return (NULL);
	while (curr->next != lst->head)
	{
		curr = curr->next;
		if (curr->val > val)
			return (curr->prev);
	}
	return (NULL);
}
