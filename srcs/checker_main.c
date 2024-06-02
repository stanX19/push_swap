/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:18:27 by shatan            #+#    #+#             */
/*   Updated: 2024/06/02 14:30:02 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_data(t_data *data)
{
	t_stringstream	*ss;
	char			*line;

	line = NULL;
	ss = ss_create_from_fd(0);
	while (errno == 0 && ss_read_line(ss, &line, "\n"))
	{
		execute_str_op(data, line, false);
		free(line);
	}
	ss_destroy(ss);
}

void	print_result(t_data *data)
{
	if (errno || !data)
		ft_dprintf(2, "Error\n");
	else if (data_is_sorted(data))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, const char **argv)
{
	t_data			*data;

	data = data_init(argc, argv);
	if (data)
		sort_data(data);
	print_result(data);
	data_delete(data);
	return (0);
}
