/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_find_node_eq.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:06:02 by shatan            #+#    #+#             */
/*   Updated: 2024/05/23 23:04:14 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*lst_find_first_eq(t_list *lst, int val)
{
	t_node	*curr;

	curr = lst->head;
	if (!curr)
		return (NULL);
	while (true)
	{
		if (curr->val == val)
			return (curr);
		curr = curr->next;
		if (curr == lst->head)
			break ;
	}
	return (NULL);
}
