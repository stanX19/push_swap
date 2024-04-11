#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_node
{
	int				val;
	int				cost;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_list
{
	t_node			*head;
}					t_list;

typedef struct s_data
{
	t_list			*a;
	t_list			*b;
}					t_data;

typedef enum e_operations
{
	SA = (1 << 0),
	SB = (1 << 1),
	SS = (1 << 2),
	PA = (1 << 3),
	PB = (1 << 4),
	RA = (1 << 5),
	RB = (1 << 6),
	RR = (1 << 7),
	RRA = (1 << 8),
	RRB = (1 << 9),
	RRR = (1 << 10),
	ALL_OP = 0b11111111111
}					t_operations;

/* Not allowed:
	- undo operation
	- this + next replacable by one operation
	- this + next is equal to next + this, AND is covered by another OP_NEXT
*/
typedef enum e_ban
{
	SA_BAN = SS | SB | SA,
	SB_BAN = SS | SB | SA,
	SS_BAN = SS | SB | SA,
	PA_BAN = PB,
	PB_BAN = PA,
	RA_BAN = RB | RRA | RR | RRR,
	RB_BAN = RA | RRB | RR | RRR,
	RR_BAN = RRA | RRB | RRR,
	RRA_BAN = RRB | RA | RRR | RR,
	RRB_BAN = RRA | RB | RRR | RR,
	RRR_BAN = RA | RB | RR
}					t_ban;

typedef enum e_allow
{
	SA_ALLOW = ALL_OP ^ SA_BAN,
	SB_ALLOW = ALL_OP ^ SB_BAN,
	SS_ALLOW = ALL_OP ^ SS_BAN,
	PA_ALLOW = PB,
	PB_ALLOW = PA,
	RA_ALLOW = RB | RRA | RR | RRR,
	RB_ALLOW = RA | RRB | RR | RRR,
	RR_ALLOW = RRA | RRB | RRR,
	RRA_ALLOW = RRB | RA | RRR | RR,
	RRB_ALLOW = RRA | RB | RRR | RR,
	RRR_ALLOW = RA | RB | RR
}					t_allow;

t_node				*new_node(int val);
t_node				*pop_node(t_node *node);
void				node_delete(t_node *node);
void				node_swap_val(t_node *n1, t_node *n2);
void				node_swap_val_with_next(t_node *node);

void				lst_push_front(t_list *list, t_node *node);
void				lst_push_back(t_list *list, t_node *node);
void				lst_append_val(t_list *list, int val);
void				lst_swap_first_2(t_list *list);
t_node				*lst_pop_front(t_list *list);
void				lst_rotate_backward(t_list *list);
void				lst_rotate_foward(t_list *list);
bool				lst_is_sorted(t_list *list);
t_list				*lst_copy(t_list *list);
t_list				*lst_new(void);
void				lst_delete(t_list *list);
void				print_list(t_list *list);
/*
sa  : swap a
	- swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
sb  : swap b
	- swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
ss  : sa and sb at the same time.
pa  : push a
	- take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
pb  : push b
	- take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
ra  : rotate a
	- shift up all elements of stack a by 1. The first element becomes the last one.
rb  : rotate b
	- shift up all elements of stack b by 1. The first element becomes the last one.
rr  : ra and rb at the same time.
rra : reverse rotate a
	- shift down all elements of stack a by 1. The last element becomes the first one.
rrb : reverse rotate b
	- shift down all elements of stack b by 1. The last element becomes the first one.
rrr : rra and rrb at the same time.
*/
void				sa(t_data *data);
void				sb(t_data *data);
void				ss(t_data *data);
void				pa(t_data *data);
void				pb(t_data *data);
void				ra(t_data *data);
void				rb(t_data *data);
void				rr(t_data *data);
void				rra(t_data *data);
void				rrb(t_data *data);
void				rrr(t_data *data);

#endif // PUSH_SWAP