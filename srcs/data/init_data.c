/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 00:23:21 by stan              #+#    #+#             */
/*   Updated: 2024/04/23 16:30:28 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	error(const char *error_type, char *details, int ret)
{
	ft_printf("Error. %s: %s\n", error_type, details);
	free(details);
	return (ret);
}

static int	init_list_a(t_list *a, const char **tokens, int len)
{
	t_stringstream	*ss;
	int				val;

	ss = ss_create_with_str(ft_tokens_join(tokens, len, " "));
	while (ss_read_int(ss, &val))
	{
		lst_append_val(a, val);
		if (lst_find_val(a, val) != -1)
			return (error("Repeating value", ft_itoa(val), -1));
	}
	if (errno == ERANGE)
		return (error("Integer out of range", ft_itoa(val), -1));
	if (errno == EINVAL)
		return (error("Not an Integer", ss_get_prev_str(ss), -1));
	ss_destroy(ss);
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
