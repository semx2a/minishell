/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_list_reverse.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:34:13 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/02 17:34:55 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	reverse(t_double_list *s)
{
	t_node	*tmp;
	void	*content;

	if (double_list_size(s) > 1)
	{
		tmp = s->tail;
		if (!tmp)
			return ;
		content = tmp->data;
		s->tail = tmp->prev;
		s->tail->next = NULL;
		putfront_double_list(s, content);
		free(tmp);
	}
}
