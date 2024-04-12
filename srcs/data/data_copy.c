/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 23:43:25 by stan              #+#    #+#             */
/*   Updated: 2024/04/12 23:43:31 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*data_copy(t_data *data)
{
	t_data	*ret;

	ret = (t_data *)malloc(sizeof(t_data));
	ret->a = lst_copy(data->a);
	ret->b = lst_copy(data->b);
	return (ret);
}
