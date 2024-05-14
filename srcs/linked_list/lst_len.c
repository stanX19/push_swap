/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 12:28:47 by stan              #+#    #+#             */
/*   Updated: 2024/05/14 19:15:08 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	lst_len(t_list *list)
{
	size_t	len;
	t_node	*curr;

	if (!list || !list->head)
		return (0);
	curr = list->head;
	len = 0;
	while (true)
	{
		len++;
		curr = curr->next;
		if (curr == list->head)
			break ;
	}
	return (len);
}
