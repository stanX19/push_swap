/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:26:09 by shatan            #+#    #+#             */
/*   Updated: 2024/04/18 14:26:09 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
# define NODE_H

typedef struct s_node
{
	int				val;
	int				cost;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

t_node				*new_node(int val);
t_node				*pop_node(t_node *node);
void				node_delete(t_node *node);
void				node_swap_val(t_node *n1, t_node *n2);
void				node_swap_val_with_next(t_node *node);

#endif  //NODE
