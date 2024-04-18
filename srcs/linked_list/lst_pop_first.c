/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_pop_first.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:18:49 by shatan            #+#    #+#             */
/*   Updated: 2024/04/18 14:18:50 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*lst_pop_front(t_list *list)
{
	t_node	*ret;

	if (!list || !list->head)
		return (NULL);
	ret = list->head;
	if (list->head->next == list->head)
		list->head = NULL;
	else
		list->head = list->head->next;
	return (pop_node(ret));
}
