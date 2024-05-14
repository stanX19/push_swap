/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:35:02 by stan              #+#    #+#             */
/*   Updated: 2024/05/14 17:37:10 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*lst_iter(t_list *list)
{
	if (!list)
		return (NULL);
	if (list->curr == NULL)
	{
		list->curr = list->head;
		return (list->curr);
	}
	list->curr = list->curr->next;
	if (list->curr == list->head)
	{
		list->curr = NULL;
		return (NULL);
	}
	return (list->curr);
}
