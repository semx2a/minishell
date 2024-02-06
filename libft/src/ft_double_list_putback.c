/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_list_putback.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:34:00 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/02 17:34:55 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	putback_double_list(t_double_list *double_list, void *content)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new = new_node(content);
	if (double_list->tail)
		double_list->tail->next = new;
	else
		double_list->head = new;
	double_list->tail = new;
}
