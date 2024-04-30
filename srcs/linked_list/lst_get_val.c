/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_get_val.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:52:13 by shatan            #+#    #+#             */
/*   Updated: 2024/04/30 15:55:07 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_get_val(t_list *lst, int idx)
{
	t_node *curr;

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
	return (curr->val);
}
