/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:58:14 by shatan            #+#    #+#             */
/*   Updated: 2024/05/10 14:15:15 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_q_node
{
	t_data			*data;
	struct s_q_node	*next;
}					t_q_node;

typedef struct s_queue
{
	t_q_node		*head;
	t_q_node		*back;
}					t_queue;

t_q_node	*q_node_new(t_data *data)
{
	t_q_node	*ret;

	ret = (t_q_node *)ft_calloc(sizeof(t_q_node), 1);
	ret->data = data;
	return (ret);
}

void	q_node_destory(t_q_node	*node)
{
	delete_data(node->data);
	free(node);
}

t_q_node	*q_node_copy(t_q_node	*node)
{
	return q_node_new(data_copy(node->data));
}

t_queue	*new_queue(void)
{
	return (t_queue *)ft_calloc(sizeof(t_queue), 1);
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
	if (q->head != NULL)
	{
		q->back->next = node;
		q->back = node;
	}
	else
	{
		q->head = node;
		q->back = node;
	}
	node->next = NULL;
}

bool	queue_empty(t_queue	*q)
{
	return (q->head == NULL);
}

void	queue_destory(t_queue *q)
{
	while(!queue_empty(q))
		q_node_destory(queue_pop(q));
	free(q);
}

void	bfs(t_data *data)
{
	t_queue	*q;

	q = new_queue();
	queue_push(q, q_node_new(data));
	while (!queue_empty(q))
	{
		t_q_node	*node = queue_pop(q);

		if (data_sorted(node->data))
		{
			int	i;
			
			i = 0;
			while (i < node->data->idx)
				execute_operation(node->data, node->data->history[i++], true);
			q_node_destory(node);
			break ;
		}
		int bit = MAX_OP;
		while (bit)
		{
			if (bit & node->data->possibility)
			{
				t_q_node	*cpy = q_node_copy(node);
				execute_operation(cpy->data, bit, 0);
				cpy->data->history[cpy->data->idx++] = bit;
				queue_push(q, cpy);
			}
			bit >>= 1;
		}
		q_node_destory(node);
	}
	queue_destory(q);
}

void	data_sort(t_data *data)
{
	bfs(data);
}
