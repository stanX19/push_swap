/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:20:55 by shatan            #+#    #+#             */
/*   Updated: 2024/05/15 19:51:40 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_push_front(t_list *list, t_node *node)
{
	if (!list || !node)
		return ;
	if (list->head)
	{
		node_link(list->head->prev, node);
		node_link(node, list->head);
	}
	else
	{
		node_link(node, node);
	}
	list->head = node;
}
