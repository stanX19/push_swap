/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_to_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:23:03 by shatan            #+#    #+#             */
/*   Updated: 2024/05/18 16:59:36 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// almost no effect cuz if +ve -ve makes a difference its already bad (middle)
// static void	lowest_cost(int *idx_a, int *idx_b, int len_a, int len_b)
// {
// 	int	*vec[4];
// 	int	i;
// 	int	min_cost;
// 	int	cost;

// 	vec[0] = (int[2]){*idx_a, *idx_b};
// 	vec[1] = (int[2]){*idx_a - len_a, *idx_b - len_b};
// 	vec[2] = (int[2]){*idx_a, *idx_b - len_b};
// 	vec[3] = (int[2]){*idx_a - len_a, *idx_b};
// 	i = 0;
// 	min_cost = INT_MAX;
// 	while (i < 4)
// 	{
// 		cost = idx_to_cost(vec[i][0], vec[i][1]);
// 		if (cost < min_cost)
// 		{
// 			*idx_a = vec[i][0];
// 			*idx_b = vec[i][1];
// 			min_cost = cost;
// 		}
// 		i++;
// 	}
// }

void	rotate_preprocess(t_data *data, int *idx_a, int *idx_b)
{
	int	len_a;
	int	len_b;

	len_a = lst_len(data->a);
	len_b = lst_len(data->b);
	if (len_a)
		*idx_a %= len_a;
	if (len_b)
		*idx_b %= len_b;
	if (*idx_a > len_a / 2)
		*idx_a -= len_a;
	if (*idx_b > len_b / 2)
		*idx_b -= len_b;
}
	//lowest_cost(idx_a, idx_b, len_a, len_b);

static void	rotate_positive(t_data *data, int *idx_a, int *idx_b, bool print)
{
	while (*idx_b > 0 && *idx_a > 0)
	{
		execute_op(data, RR, print);
		(*idx_b)--;
		(*idx_a)--;
	}
	while (*idx_b > 0)
	{
		execute_op(data, RB, print);
		(*idx_b)--;
	}
	while (*idx_a > 0)
	{
		execute_op(data, RA, print);
		(*idx_a)--;
	}
}

static void	rotate_negative(t_data *data, int *idx_a, int *idx_b, bool print)
{
	while (*idx_b < 0 && *idx_a < 0)
	{
		execute_op(data, RRR, print);
		(*idx_b)++;
		(*idx_a)++;
	}
	while (*idx_b < 0)
	{
		execute_op(data, RRB, print);
		(*idx_b)++;
	}
	while (*idx_a < 0)
	{
		execute_op(data, RRA, print);
		(*idx_a)++;
	}
}

void	rotate_to_top(t_data *data, int idx_a, int idx_b, bool print)
{
	rotate_preprocess(data, &idx_a, &idx_b);
	rotate_positive(data, &idx_a, &idx_b, print);
	rotate_negative(data, &idx_a, &idx_b, print);
}
