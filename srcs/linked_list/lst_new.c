/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:18:57 by shatan            #+#    #+#             */
/*   Updated: 2024/04/18 14:21:08 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lst_new(void)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list)
		list->head = NULL;
	return (list);
}
