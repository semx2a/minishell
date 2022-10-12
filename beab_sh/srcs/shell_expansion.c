/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:42:51 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/11 20:15:01 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*find_args(t_stack *s, int id)
{
	t_node	*tmp;

	tmp = s->head;
	while (tmp)
	{
		if (tmp->type == id)
			return (tmp->arg);
		tmp = tmp->next;
	}
	return (NULL);
}

size_t	type_occurrences(t_stack *s, int id)
{
	t_node	*tmp;
	size_t	len;

	tmp = s->head;
	len = 0;
	while (tmp)
	{
		if (tmp->type == id)
			len++;
		tmp = tmp->next;
	}
	return (len);
}

int	expansion(t_main *m)
{
	if (type_occurrences(m->o.tokens, INFILE_ID) != NULL)
		ft_open(&m->o.fd_in, find_arg(m->o.tokens, INFILE_ID), O_RDONLY, NULL);
	if (type_occurrences(m->o.tokens, OUTFILE_ID) != NULL)
		ft_open(&m->o.fd_out, find_arg(m->o.tokens, OUTFILE_ID),
			O_CREAT | O_TRUNC | O_WRONLY, 0644);
	m->o.paths = ft_split(get_cont("PATH", m->env), ':');
	m->o.cmd_nb = type_occurrences(m->o.tokens, CMD_ID);
	m->o.pipe_nb = type_occurrences(m->o.tokens, PIPE_ID);
	if (m->o.pipe_nb > 0)
		ft_assign_pipes(&m->o);
	m->o.index = 0;
	return (1);
}
