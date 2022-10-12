/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_lexer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:15:54 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/12 18:20:01 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	put_back_lexer(t_stack *stack, int type, char *str)
{
	t_node	*new;

	new = xmalloc(sizeof(t_node));
	new->arg = str;
	new->type = type;
	new->prev = stack->tail;
	new->next = NULL;
	if (stack->tail)
		stack->tail->next = new;
	else
		stack->head = new;
	stack->tail = new;
}

void	put_front_lexer(t_stack *stack, int type, char *str)
{
	t_node	*new;

	new = xmalloc(sizeof(t_node));
	new->arg = str;
	new->type = type;
	new->next = stack->head;
	new->prev = NULL;
	if (stack->head)
		stack->head->prev = new;
	else
		stack->tail = new;
	stack->head = new;
}

void	print_lexer(t_stack *stack)
{
	void	*tmp;
	int		i;

	tmp = (void *)stack->head;
	i = 0;
	while (tmp)
	{
		printf(" Node #%d type = %d arg = %s\n", i, (t_lexer *)tmp->type, (t_lexer *)tmp->arg);
		printf(" ------------------ \n");
		i++;
		tmp = (void *)tmp->next;
	}
}


void	free_lexer(t_lexer *l)
{
	t_lexer	*tmp;

	while (l)
	{
		tmp = l;
		l = l->next;
		free(tmp);
	}
	l = NULL;
	free(p);
}

size_t	lexer_size(t_lexer *l)
{
	size_t	size;
	t_lexer	*tmp;

	size = 0;
	tmp = l;
	if (l)
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