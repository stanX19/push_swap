/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 00:23:21 by stan              #+#    #+#             */
/*   Updated: 2024/05/29 12:52:06 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_list_a(t_list *a, const char **tokens, int len)
{
	t_stringstream	*ss;
	int				val;
	char			*str;

	str = ft_tokens_join(tokens, len, " ");
	ss = ss_create_use_provided(str);
	while (errno == 0 && ss_read_int(ss, &val))
	{
		if (!ft_isspace_or_null(ss_peek(ss)))
			errno = EINVAL;
		if (lst_find_val(a, val) != -1)
			errno = EINVAL;
		lst_append_val(a, val);
	}
	ss_destroy(ss);
	if (errno == 0 && lst_len(a) > 0)
		return (0);
	ft_dprintf(2, "Error\n");
	return (-1);
}

t_data	*data_init(int argc, const char **argv)
{
	t_data	*ret;

	ret = (t_data *)malloc(sizeof(t_data));
	if (!ret)
		return (ret);
	ret->a = lst_new();
	ret->b = lst_new();
	if (init_list_a(ret->a, ++argv, --argc))
	{
		data_delete(ret);
		ret = NULL;
	}
	return (ret);
}
