/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:14:27 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/05 17:52:15 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	init_stack(t_stack *stack)
{
	stack->head = NULL;
	stack->tail = NULL;
}

void	free_stack(t_stack *stack)
{
	t_node	*tmp;

	while (stack->head)
	{
		tmp = stack->head;
		stack->head = stack->head->next;
		free(tmp);
	}
	stack->head = NULL;
	stack->tail = NULL;
	free(stack);
}

int	stack_size(t_stack *stack)
{
	int		size;
	t_node	*tmp;

	size = 0;
	tmp = stack->head;
	if (stack)
	{
		if (tmp)
		{
			while (tmp)
			{
				tmp = tmp->next;
				size++;
			}
			return (size);
		}
	}
	return (0);
}
