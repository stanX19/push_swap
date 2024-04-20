/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:16:34 by shatan            #+#    #+#             */
/*   Updated: 2024/04/20 17:16:58 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	main(int argc, const char **argv)
// {
// 	t_data	*data;

// 	data = init_data(argc, argv);
// 	if (!data)
// 		return (1);
// 	print_list(data->a);
// 	delete_data(data);
// 	return (0);
// }

int	main(int argc, const char **argv)
{
	t_stringstream	*ss;
	double			val;

	if (argc < 2)
		return (0);
	ss = sstream_new(argv[1]);
	val = 0;
	while (sstream_read_double(sstream_to_numeric(ss), &val))
	{
		ft_printf("%20f\n", val);
		errno = 0;
	}
	sstream_destroy(ss);
}
