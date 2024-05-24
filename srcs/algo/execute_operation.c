/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 12:26:35 by stan              #+#    #+#             */
/*   Updated: 2024/05/24 15:33:04 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static const t_op_dict	*get_op_dict(void)
{
	static const t_op_dict	op_dict[] = {
	{SA, sa, "sa"},
	{SB, sb, "sb"},
	{SS, ss, "ss"},
	{PA, pa, "pa"},
	{PB, pb, "pb"},
	{RA, ra, "ra"},
	{RB, rb, "rb"},
	{RR, rr, "rr"},
	{RRA, rra, "rra"},
	{RRB, rrb, "rrb"},
	{RRR, rrr, "rrr"},
	{0, NULL, NULL},
	};

	return (op_dict);
}

static void	print_op(t_data *data, const char *op_str, int count)
{
	static int		display = -1;

	if (display == -1)
		display = ft_path_exists("./_DISPLAY");
	if (display)
	{
		ft_printf("%8i) %4s |\t", count, op_str);
		data_print(data);
	}
	else
		ft_printf("%s\n", op_str);
}

t_data	*execute_op(t_data *data, t_op_enum op_key, bool print)
{
	static int		count = 0;
	const t_op_dict	*op_dict = get_op_dict();
	int				idx;

	if (data == NULL)
		return (NULL);
	idx = 0;
	while (op_dict[idx].func)
	{
		if (op_dict[idx].key == op_key)
		{
			op_dict[idx].func(data);
			if (print)
				print_op(data, op_dict[idx].str, count++);
			return (data);
		}
		idx++;
	}
	ft_printf("Error: no such operation %i\n", op_key);
	return (NULL);
}

t_data	*exec_op_print(t_data *data, t_op_enum op_key)
{
	return (execute_op(data, op_key, true));
}

t_data	*execute_operation_str(t_data *data, const char *op_str)
{
	const t_op_dict	*op_dict;
	int				idx;

	op_dict = get_op_dict();
	idx = 0;
	if (data == NULL)
		return (NULL);
	while (op_dict[idx].func)
	{
		if (ft_strequ(op_dict[idx].str, op_str))
		{
			op_dict[idx].func(data);
			ft_printf("%s\n", op_dict[idx].str);
			return (data);
		}
		idx++;
	}
	ft_printf("Error: no such operation: %s\n", op_str);
	return (NULL);
}
