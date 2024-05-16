/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_get_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:52:13 by shatan            #+#    #+#             */
/*   Updated: 2024/05/16 12:03:30 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*lst_get_node(t_list *lst, int idx)
{
	t_node	*curr;

	curr = lst->head;
	if (!curr)
		return (0);
	while (idx > 0)
	{
		curr = curr->next;
		idx--;
	}
	while (idx < 0)
	{
		curr = curr->prev;
		idx++;
	}
	return (curr);
}
