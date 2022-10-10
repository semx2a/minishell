/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:30:21 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/09 21:30:47 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	identify_opt()
{
}

void	identify_cmd()
{
}

void	parser(t_main *m)
{
	t_node	*tmp;

	tmp = m->o.tokens->head;
	while (tmp)
	{
		if (tmp->type == WORD)
			identify_cmd();
		if (tmp->type == OPERATOR)
			identify_opt();
		tmp = tmp->next;
	}
	free(m->o.tokens);
}
