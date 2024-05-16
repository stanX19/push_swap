/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:47:24 by shatan            #+#    #+#             */
/*   Updated: 2024/05/16 12:30:56 by stan             ###   ########.fr       */
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
	usleep(2000);
}
