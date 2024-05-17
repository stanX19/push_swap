/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_swap_with_next.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:17:46 by shatan            #+#    #+#             */
/*   Updated: 2024/05/17 15:18:59 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	node_swap_with_next(t_node *a)
// {
// 	t_node	*prev;
// 	t_node	*next;
// 	t_node	*b;

// 	if (!a || !a->next || a == a->next)
// 		return ;
// 	prev = a->prev;
// 	b = a->next;
// 	next = b->next;
// 	node_link(prev, b);
// 	node_link(b, a);
// 	node_link(a, next);
// }
void	node_swap_with_next(t_node *a)
{
	t_node	*next;

	if (!a || !a->next || a == a->next)
		return ;
	next = a->next;
	ft_int_swap(&a->cost, &next->cost);
	ft_int_swap(&a->val, &next->val);
}