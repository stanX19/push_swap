#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	int				val;
	int				cost;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_data
{
	t_list	*a;
	t_list	*b;
}	t_data;

/*
sa  : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
sb  : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
ss  : sa and sb at the same time.
pa  : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
pb  : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
ra  : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
rb  : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
rr  : ra and rb at the same time.
rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
rrr : rra and rrb at the same time.
*/
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);



#endif // PUSH_SWAP