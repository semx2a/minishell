/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:23:04 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/14 22:29:43 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	print_lexer(t_node *l)
{
	t_node	*tmp;
	int		i;

	tmp = l;
	i = 0;
	while (tmp)
	{
		printf(" Node #%d type = %d arg = %c\n", i,
			((t_lexer *)tmp->data)->type, ((t_lexer *)tmp->data)->arg);
		printf(" ------------------ \n");
		i++;
		tmp = tmp->next;
	}
}

void	print_parser(t_node *p)
{
	t_node	*tmp;
	int		i;
	int		j;

	tmp = p;
	i = 0;
	while (tmp)
	{
		printf(" Node #%d type = %d av[%i] = %s\n", i,
			((t_parser *)tmp->data)->id, 0, ((t_parser *)tmp->data)->av[0]);
		j = 1;
		while (((t_parser *)tmp->data)->av[j])
		{
			printf("                 av[%i] = %s\n", j,
				((t_parser *)tmp->data)->av[j]);
			j++;
		}
		printf(" ------------------ \n");
		i++;
		tmp = tmp->next;
	}
}

void	print_redir(t_node *r)
{
	t_node	*tmp;
	int		i;

	tmp = r;
	i = 0;
	while (tmp)
	{
		printf(" Node #%d type = %d\n", i, ((t_redir *)tmp->data)->id);
		printf(" ------------------ \n");
		i++;
		tmp = tmp->next;
	}
}