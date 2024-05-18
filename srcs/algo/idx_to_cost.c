/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idx_to_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:09:02 by shatan            #+#    #+#             */
/*   Updated: 2024/05/18 14:09:02 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	norm_idx_cost(int idx, int len)
{
	if (idx > len / 2)
		return (len - idx);
	else
		return (idx);
}

int	idx_to_cost(int idx_a, int idx_b)
{
	if (ft_sign(idx_a) == ft_sign(idx_b))
	{
		return (ft_max(ft_abs(idx_a), ft_abs(idx_b)) + 1);
	}
	return (ft_abs(idx_a) + ft_abs(idx_b) + 1);
}
