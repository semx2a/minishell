/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_list_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:33:39 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/02 17:34:55 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_double_list(t_double_list *double_list)
{
	t_node	*tmp;

	while (double_list->head)
	{
		tmp = double_list->head;
		double_list->head = double_list->head->next;
		free(tmp);
	}
	double_list->head = NULL;
	double_list->tail = NULL;
	free(double_list);
}
