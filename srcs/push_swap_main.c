/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:16:34 by shatan            #+#    #+#             */
/*   Updated: 2024/05/29 12:52:06 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, const char **argv)
{
	t_data	*data;

	data = data_init(argc, argv);
	if (!data)
		return (1);
	push_swap(data);
	data_delete(data);
	return (0);
}
