/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:09:37 by shatan            #+#    #+#             */
/*   Updated: 2024/05/18 13:09:37 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_median(t_list *list)
{
	int		ret;
	t_list	*cpy;

	cpy = lst_sort_val(lst_copy(list));
	ret = lst_get_val(cpy, lst_len(cpy) / 2);
	lst_delete(cpy);
	return (ret);
}