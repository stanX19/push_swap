/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 12:28:47 by stan              #+#    #+#             */
/*   Updated: 2024/05/14 17:36:28 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	lst_len(t_list *list)
{
	size_t	len;

	if (!list || !list->head)
		return (0);
	len = 0;
	while (lst_iter(list))
		len++;
	return (len);
}
