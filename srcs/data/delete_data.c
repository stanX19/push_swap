/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 00:23:26 by stan              #+#    #+#             */
/*   Updated: 2024/05/29 12:51:52 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	data_delete(t_data *data)
{
	if (!data)
		return ;
	lst_delete(data->a);
	lst_delete(data->b);
	free(data);
}
