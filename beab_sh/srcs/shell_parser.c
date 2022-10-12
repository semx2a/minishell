/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:30:21 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/11 20:08:07 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	identify_operator(t_node *node, char **operators)
{
	int	i;

	i = 0;
	while (operators[i])
	{
		if (!ft_strncmp(operators[i], node->arg, ft_strlen(node->arg)))
		{
			node->type = (t_operator)i;
			break ;
		}
		i++;
	}
}

void	identify_operand(t_node *node)
{
	if (!ft_strncmp("access", node->arg, ft_strlen(node->arg)))
		node->type = CMD_ID;
	else if (!ft_strncmp("-", node->arg, ft_strlen(node->arg)))
		node->type = FLAG_ID;
	else if (!ft_strncmp("", node->arg, ft_strlen(node->arg)))
		node->type = ARG_ID;
	else if (!ft_strncmp("", node->arg, ft_strlen(node->arg)))
		node->type = INFILE_ID;
	else if (!ft_strncmp("", node->arg, ft_strlen(node->arg)))
		node->type = OUTFILE_ID;
}

int	parser(t_main *m)
{
	t_node	*tmp;

	tmp = m->o.tokens->head;
	while (tmp)
	{
		if (tmp->type == WORD)
			identify_operand(tmp);
		else
			identify_operator(tmp, m->operators);
		tmp = tmp->next;
	}
	free(m->o.tokens);
	return (1);
}
