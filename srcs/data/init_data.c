/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 00:23:21 by stan              #+#    #+#             */
/*   Updated: 2024/04/18 14:27:02 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	error(const char *error_type, const char *details, int ret)
{
	ft_printf("Error. %s: %s\n", error_type, details);
	return (ret);
}

static int	init_list_a(t_list *a, const char **tokens, int len)
{
	int	i;
	int	val;

	i = 0;
	while (i < len)
	{
		val = ft_atoi(tokens[i]);
		if (errno == ERANGE)
			return (error("Integer out of range", tokens[i], -1));
		if (errno == EINVAL)
			return (error("Not an Integer", tokens[i], -1));
		if (lst_find_val(a, val) != -1)
			return (error("Repeating value", tokens[i], -1));
		lst_append_val(a, val);
		i++;
	}
	return (0);
}

t_data	*init_data(int argc, const char **argv)
{
	t_data	*ret;

	ret = (t_data *)malloc(sizeof(t_data));
	if (!ret)
		return (ret);
	ret->a = lst_new();
	ret->b = lst_new();
	if (init_list_a(ret->a, ++argv, --argc))
	{
		delete_data(ret);
		ret = NULL;
	}
	return (ret);
}
