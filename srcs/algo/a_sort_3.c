/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_sort_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:08:22 by shatan            #+#    #+#             */
/*   Updated: 2024/05/18 14:09:52 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_status(t_list *list)
{
	t_node	*curr;
	int		status;
	int		bit;

	curr = list->head;
	status = 0;
	bit = 1;
	while (curr->prev != list->head)
	{
		status += bit * (curr->prev->val > curr->val);
		bit <<= 1;
		curr = curr->prev;
	}
	status += bit * (curr->prev->val > curr->val);
	return (status);
}

void	a_sort_3(t_data *data)
{
	int	status;

	status = get_status(data->a);
	if (status == 3 || status == 5 || status == 6)
		exec_op_print(data, SA);
}
