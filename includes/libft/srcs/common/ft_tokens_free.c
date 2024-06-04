/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokens_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 22:50:33 by stan              #+#    #+#             */
/*   Updated: 2024/04/12 23:20:12 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tokens_free(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i++]);
	}
	free(tokens);
}