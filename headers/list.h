/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:26:13 by shatan            #+#    #+#             */
/*   Updated: 2024/04/30 14:42:58 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H
# include <stdbool.h>
# include "node.h"

typedef struct s_list
{
	t_node	*head;
}			t_list;

void		lst_push_front(t_list *list, t_node *node);
void		lst_push_back(t_list *list, t_node *node);
void		lst_append_val(t_list *list, int val);
void		lst_swap_first_2(t_list *list);
t_node		*lst_pop_front(t_list *list);
void		lst_rotate_backward(t_list *list);
void		lst_rotate_foward(t_list *list);
bool		lst_is_sorted(t_list *list);
t_list		*lst_copy(t_list *list);
t_list		*lst_new(void);
size_t		lst_len(t_list *list);
void		lst_delete(t_list *list);
void		print_list(t_list *list);
int			lst_find_val(t_list *lst, int val);

#endif // LIST
