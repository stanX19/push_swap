/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:18:03 by shatan            #+#    #+#             */
/*   Updated: 2024/05/16 12:22:04 by stan             ###   ########.fr       */
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
