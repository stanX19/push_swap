/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 00:23:21 by stan              #+#    #+#             */
/*   Updated: 2024/04/13 00:25:57 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*init_data(int argc, const char **argv)
{
	t_data	*ret;
	int		i;
	int		val;

	ret = (t_data *)malloc(sizeof(t_data));
	if (!ret)
		return (ret);
	ret->a = lst_new();
	ret->b = lst_new();
	i = 1;
	while (i < argc)
	{
		val = ft_atoi(argv[i]);
		if (errno == ERANGE || errno == EINVAL)
		{
			delete_data(ret);
			ft_printf("nuh uh");
			return (0);
		}
		lst_append_val(ret->a, val);
		i++;
	}
	return (ret);
}