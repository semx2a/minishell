/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_list_push.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:33:50 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/02 17:34:55 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	push(t_double_list *a, t_double_list *b)
{	
	t_node	*tmp;
	void	*content;

	if (double_list_size(b) != 0)
	{
		tmp = b->head;
		if (!tmp)
			return ;
		content = tmp->data;
		putfront_double_list(a, content);
		b->head = b->head->next;
		if (b->head)
			b->head->prev = NULL;
		free(tmp);
	}
}
