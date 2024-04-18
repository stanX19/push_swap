/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_swap_val_with_next.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:17:46 by shatan            #+#    #+#             */
/*   Updated: 2024/04/18 14:17:49 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	node_swap_val_with_next(t_node *node)
{
	if (!node || !node->next || node == node->next)
		return ;
	node_swap_val(node, node->next);
}
