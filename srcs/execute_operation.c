/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 12:26:35 by stan              #+#    #+#             */
/*   Updated: 2024/05/15 20:24:35 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static const t_op_dict	*get_op_dict(void)
{
	static const t_op_dict op_dict[] = {
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

t_data	*execute_op(t_data *data, t_op_enum op_key)
{
	static int		count;
	const t_op_dict	*op_dict;
	int				idx;

	op_dict = get_op_dict();
	idx = 0;
	if (data == NULL)
		return (NULL);
	while (op_dict[idx].func)
	{
		if (op_dict[idx].key == op_key)
		{
			op_dict[idx].func(data);
			ft_printf("%8i) %4s |\n", count++, op_dict[idx].str);
			//data_print(data);
			return (data);
		}
		idx++;
	}
	ft_printf("Error: no such operation %i\n", op_key);
	return (NULL);
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
