/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:26:13 by shatan            #+#    #+#             */
/*   Updated: 2024/05/23 23:05:00 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H
# include "node.h"
# include <stdbool.h>

typedef struct s_list
{
	t_node	*head;
	t_node	*curr;
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
t_node		*lst_iter(t_list *list);
size_t		lst_len(t_list *list);
void		lst_delete(t_list *list);
void		lst_print(t_list *list);
int			lst_find_val(t_list *lst, int val);
t_node		*lst_find_first_eq(t_list *lst, int val);
t_node		*lst_find_first_leq(t_list *sorted_lst, int val);
int			lst_get_val(t_list *lst, int idx);
t_node		*lst_get_node(t_list *lst, int idx);
t_list		*lst_sort_val(t_list *list);
t_list		*lst_sort_cost(t_list *list);
int			lst_median(t_list *list);

#endif // LIST
