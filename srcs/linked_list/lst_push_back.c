/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:18:41 by shatan            #+#    #+#             */
/*   Updated: 2024/04/18 14:18:43 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_push_back(t_list *list, t_node *node)
{
	if (!list || !node)
		return ;
	lst_push_front(list, node);
	lst_rotate_backward(list);
}
