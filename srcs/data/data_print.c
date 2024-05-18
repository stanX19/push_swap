/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:47:24 by shatan            #+#    #+#             */
/*   Updated: 2024/05/18 13:51:20 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	data_print(t_data *data)
{
	if (lst_len(data->a) + lst_len(data->b) > 20)
	{
		ft_printf("\n");
		return ;
	}
	ft_printf("a: ");
	lst_print(data->a);
	ft_printf("\t\tb: ");
	lst_print(data->b);
	ft_printf("\n");
	usleep(2000);
}
