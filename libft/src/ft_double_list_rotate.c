/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_list_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:34:19 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/02 17:34:55 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	rotate(t_double_list *s)
{
	void	*content;
	t_node	*tmp;

	if (double_list_size(s) > 1)
	{
		tmp = s->head;
		if (!tmp)
			return ;
		content = tmp->data;
		s->head = tmp->next;
		s->head->prev = NULL;
		putback_double_list(s, content);
		free(tmp);
	}
}
