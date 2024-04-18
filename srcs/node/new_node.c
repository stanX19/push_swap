/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:18:10 by shatan            #+#    #+#             */
/*   Updated: 2024/04/18 14:20:46 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int val)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node)
	{
		node->val = val;
		node->cost = 0;
		node->next = NULL;
		node->prev = NULL;
	}
	return (node);
}
