/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_count_val.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:39:06 by shatan            #+#    #+#             */
/*   Updated: 2024/05/26 16:14:58 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_2d_count_val(char **map, int width, int height, char target)
{
	int	count;
	int	j;
	int	i;

	count = 0;
	j = 0;
	while (j < height)
	{
		i = 0;
		while (i < width)
		{
			if (map[j][i] == target)
				++count;
			++i;
		}
		++j;
	}
	return (count);
}
int	ft_2d_count_charset(char **map, int width, int height, char *charset)
{
	int	count;
	int	j;
	int	i;

	count = 0;
	j = 0;
	while (j < height)
	{
		i = 0;
		while (i < width)
		{
			if (ft_strchr(charset, map[j][i]))
				++count;
			++i;
		}
		++j;
	}
	return (count);
}
