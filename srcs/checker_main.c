/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:18:27 by shatan            #+#    #+#             */
/*   Updated: 2024/05/29 13:17:03 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stringstream	*get_ss(void)
{
	char	buffer[320000];
	int		idx;
	ssize_t	rd_size;

	rd_size = 1;
	idx = 0;
	while (errno == 0 && rd_size != 0)
	{
		rd_size = read(0, buffer + idx, sizeof(buffer) - idx * sizeof(char));
		idx += rd_size;
	}
	buffer[idx] = '\0';
	return (ss_create(buffer));
}

int	main(int argc, const char **argv)
{
	t_data			*data;
	t_stringstream	*ss;
	char			*line;

	data = data_init(argc, argv);
	ss = NULL;
	line = NULL;
	if (data)
		ss = get_ss();
	while (errno == 0 && ss_read_line(ss, &line, "\n"))
	{
		execute_str_op(data, line, false);
		free(line);
	}
	if (errno)
		ft_dprintf(2, "ERROR\n");
	else if (data_is_sorted(data))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ss_destroy(ss);
	data_delete(data);
	return (0);
}
