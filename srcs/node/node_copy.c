/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:18:03 by shatan            #+#    #+#             */
/*   Updated: 2024/05/18 11:29:10 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*node_copy(t_node *node)
{
	t_node	*cpy;

	cpy = (t_node *)ft_calloc(sizeof(t_node), 1);
	ft_memcpy(cpy, node, sizeof(t_node));
	cpy->next = NULL;
	cpy->prev = NULL;
	return (cpy);
}
