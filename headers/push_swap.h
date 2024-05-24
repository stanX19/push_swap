/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:26:03 by shatan            #+#    #+#             */
/*   Updated: 2024/05/24 13:45:55 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "list.h"
# include "node.h"
# ifdef DISPLAY
#  undef DISPLAY
#  define DISPLAY true
# else
#  define DISPLAY false
# endif
typedef struct s_data
{
	t_list		*a;
	t_list		*b;
}				t_data;

// algo
int				calculate_pa_cost(t_data *data, int depth, size_t max_branch);
int				calculate_pb_cost(t_data *data, int max_accept_val);
void			rotate_preprocess(t_data *data, int *idx_a, int *idx_b);
void			rotate_to_top(t_data *data, int idx_a, int idx_b, bool print);
void			pa_lowest_cost(t_data *data, bool print);
void			pb_lowest_cost(t_data *data, bool print);
void			a_sort_3(t_data *data);
int				get_smallest_idx(t_list *list);
int				get_largest_idx(t_list *list, int max_accept);
int				get_lowest_cost_idx(t_list *list);
int				norm_idx_cost(int idx, int len);
int				idx_to_cost(int idx_a, int idx_b);
void			push_swap(t_data *data);

// data
t_data			*data_copy(t_data *data);
void			delete_data(t_data *data);
t_data			*init_data(int argc, const char **argv);
bool			data_is_sorted(t_data *data);
void			data_print(t_data *data);

t_data			*sa(t_data *data);
t_data			*sb(t_data *data);
t_data			*ss(t_data *data);
t_data			*pa(t_data *data);
t_data			*pb(t_data *data);
t_data			*ra(t_data *data);
t_data			*rb(t_data *data);
t_data			*rr(t_data *data);
t_data			*rra(t_data *data);
t_data			*rrb(t_data *data);
t_data			*rrr(t_data *data);

/*
sa  : swap a
	-	swap the first 2 elements at the top of stack a.
		Do nothing if there is only one or no elements).
sb  : swap b
	-	swap the first 2 elements at the top of stack b.
		Do nothing if there is only one or no elements).
ss  : sa and sb at the same time.
pa  : push a
	-	take the first element at the top of b and put it
		at the top of a. Do nothing if b is empty.
pb  : push b
	-	take the first element at the top of a and put it
		at the top of b. Do nothing if a is empty.
ra  : rotate a
	-	shift up all elements of stack a by 1. The first
		element becomes the last one.
rb  : rotate b
	-	shift up all elements of stack b by 1. The first
		element becomes the last one.
rr  : ra and rb at the same time.
rra : reverse rotate a
	-	shift down all elements of stack a by 1. The last
		element becomes the first one.
rrb : reverse rotate b
	-	shift down all elements of stack b by 1. The last
		element becomes the first one.
rrr : rra and rrb at the same time.
*/

typedef enum e_op_enum
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
}				t_op_enum;

typedef struct s_op_dict
{
	t_op_enum	key;
	t_data		*(*func)(t_data *);
	const char	*str;
}				t_op_dict;

t_data			*exec_op_print(t_data *data, t_op_enum op_key);
t_data			*execute_op(t_data *data, t_op_enum op_key, bool print);

#endif // PUSH_SWAP