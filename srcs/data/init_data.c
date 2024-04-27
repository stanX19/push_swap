/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 00:23:21 by stan              #+#    #+#             */
/*   Updated: 2024/04/27 13:06:28 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline int	handle_error()
{
	if (errno == 0)
		return (0);
	ft_printf("Error\n");
	return (-1);
}

static int	init_list_a(t_list *a, const char **tokens, int len)
{
	t_stringstream	*ss;
	int				val;

	ss = ss_create_use_provided(ft_tokens_join(tokens, len, " "));
	while (errno == 0 && ss_read_int(ss, &val))
	{
		if (lst_find_val(a, val) != -1)
			errno = -1;
		lst_append_val(a, val);
	}
	ss_destroy(ss);
	return (handle_error());
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
