/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:58:14 by shatan            #+#    #+#             */
/*   Updated: 2024/05/06 13:15:40 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_q_node
{
	t_data			*data;
	int				history[5000];
	int				idx;
	struct s_q_node	*next;
}					t_q_node;

typedef struct s_queue
{
	t_q_node		*head;
	t_q_node		*back;
}					t_queue;

t_queue	*new_queue(void)
{
	t_queue	*q;

	q = (t_queue *)malloc(sizeof(t_queue));
	q->head = NULL;
	q->back = NULL;
	return (q);
}

t_q_node	*queue_pop(t_queue *q)
{
	t_q_node	*ret;

	ret = q->head;
	if (q->head)
	{
		q->head = q->head->next;
		if (q->head == NULL)
			q->back = NULL;
		ret->next = NULL;
	}
	return (ret);
}

void	queue_push(t_queue *q, t_q_node *node)
{
	if (q->head != NULL){
		q->back->next = node;
		q->back = node;
	}
	else {
		q->head = node;
		q->back = node;
	}
	node->next = NULL;
}

void	bfs(t_data *data)
{
	t_q_node	*queue;
}

void	data_sort(t_data *data)
{
	bfs(data);
}
