/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_find_val.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:06:02 by shatan            #+#    #+#             */
/*   Updated: 2024/05/23 23:01:30 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_find_val(t_list *lst, int val)
{
	t_node	*curr;
	int		idx;

	idx = 0;
	curr = lst->head;
	if (!curr)
		return (-1);
	while (curr->next != lst->head)
	{
		if (curr->val == val)
			return (idx);
		idx++;
		curr = curr->next;
	}
	if (curr->val == val)
		return (idx);
	return (-1);
}
