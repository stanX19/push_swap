/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:21:41 by shatan            #+#    #+#             */
/*   Updated: 2024/05/16 11:57:38 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lst_copy(t_list *list)
{
	t_list	*copy;
	t_node	*src_curr;

	if (!list)
		return (NULL);
	copy = lst_new();
	if (!list->head)
		return (copy);
	src_curr = list->head;
	lst_push_back(copy, node_copy(src_curr));
	src_curr = src_curr->next;
	while (src_curr != list->head)
	{
		lst_push_back(copy, node_copy(src_curr));
		src_curr = src_curr->next;
	}
	return (copy);
}
