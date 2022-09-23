/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:29:12 by seozcan           #+#    #+#             */
/*   Updated: 2022/09/23 17:31:16 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

//static void	update_pos(t_stack *stack)
//{
//	t_obj	o;
//
//	o = (t_obj){0};
//	o.tmp_hd = stack->head;
//	o.i = 0;
//	o.size = stack_size(stack);
//	while (o.i < o.size)
//	{
//		o.tmp_hd->pos = o.i;
//		o.i++;
//		o.tmp_hd = o.tmp_hd->next;
//	}
//}
//
//void	update_idx(t_stack *stack)
//{
//	t_obj	o;
//
//	o = (t_obj){0};
//	o.tmp_hd = stack->head;
//	o.tmp_tl = stack->tail;
//	o.i = 0;
//	o.j = -1;
//	o.size = stack_size(stack);
//	while (o.i < o.size / 2)
//	{
//		o.tmp_hd->idx = o.i;
//		o.tmp_tl->idx = o.j;
//		o.i++;
//		o.j--;
//		o.tmp_hd = o.tmp_hd->next;
//		o.tmp_tl = o.tmp_tl->prev;
//	}
//	if (o.size % 1 == 0)
//		o.tmp_hd->idx = o.i;
//	update_pos(stack);
//}

void	put_back(t_stack *stack, int type, char *arg)
{
	t_node	*new;

	new = xmalloc(sizeof(t_node));
	new->type = type;
	new->arg = ft_strdup(arg);
	new->prev = stack->tail;
	new->next = NULL;
	if (stack->tail)
		stack->tail->next = new;
	else
		stack->head = new;
	stack->tail = new;
}

void	put_front(t_stack *stack, int type, char *arg)
{
	t_node	*new;

	new = xmalloc(sizeof(t_node));
	new->type = type;
	new->arg = ft_strdup(arg);
	new->next = stack->head;
	new->prev = NULL;
	if (stack->head)
		stack->head->prev = new;
	else
		stack->tail = new;
	stack->head = new;
}

void	print_list(t_stack *stack)
{
	t_node	*tmp;
	int		i;

	tmp = stack->head;
	i = 0;
	while (tmp)
	{
		printf(" ------Node #%d----- \n", i);
		printf("|\n");
		printf("| type	= %d\n", tmp->type);
		printf("| arg	= %s\n", tmp->arg);
		printf("|\n");
		printf(" ------------------ \n");
		i++;
		tmp = tmp->next;
	}
}
