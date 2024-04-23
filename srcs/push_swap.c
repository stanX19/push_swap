/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:16:34 by shatan            #+#    #+#             */
/*   Updated: 2024/04/23 15:18:03 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, const char **argv)
{
	t_data	*data;

	data = init_data(argc, argv);
	if (!data)
		return (1);
	print_list(data->a);
	delete_data(data);
	return (0);
}

// int	main(int argc, const char **argv)
// {
// 	t_stringstream	*ss;
// 	double			val;
// 	char			*s;

// 	if (argc < 2)
// 		return (0);
// 	ss = ss_create(argv[1]);
// 	val = 0;
// 	while (ss_read_double(ss, &val))
// 		ft_printf("%20f\n", val);
// 	if (!ss_eof(ss))
// 	{
// 		s = NULL;
// 		ss_read_line(ss, &s, " ");
// 		ft_printf("error: %s\n", s);
// 		free(s);
// 	}
// 	ss_destroy(ss);
// }
