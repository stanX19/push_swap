/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_append_to_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:36:41 by shatan            #+#    #+#             */
/*   Updated: 2024/06/02 14:19:44 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stringstream_private.h"

// appends str to the stringstream for furthur processing
t_stringstream	*ss_append(t_stringstream *ss, const char *str)
{
	char	*original;
	int		idx;

	if (ss == NULL || ss->str == NULL)
		return (NULL);
	original = ss->str;
	idx = ss->pos - ss->str;
	ss->str = ft_strjoin(original, str);
	ss->pos = ss->str + idx;
	free(original);
	return (ss);
}
