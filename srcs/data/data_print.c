/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:47:24 by shatan            #+#    #+#             */
/*   Updated: 2024/05/14 19:39:35 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	data_print(t_data *data)
{
	ft_printf("a: ");
	lst_print(data->a);
	ft_printf("\t\tb: ");
	lst_print(data->b);
	ft_printf("\n");
	usleep(200000);
}
