/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_flush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:50:50 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/14 23:35:29 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	free_redir(t_node **r)
{
	t_node	*tmp;

	tmp = *r;
	while (tmp)
	{
		close(((t_redir *)tmp->data)->pipe[0]);
		close(((t_redir *)tmp->data)->pipe[1]);
		free(((t_redir *)tmp->data)->path);
		free(((t_redir *)tmp->data));
		tmp = tmp->next;
	}
	free_nodes(r, &free);
}

void	free_parser(t_node **p)
{
	t_node	*tmp;

	tmp = *p;
	while (tmp)
	{
		if (((t_parser *)tmp->data)->is_piped == 1)
		{
			close(((t_parser *)tmp->data)->pipe[0]);
			close(((t_parser *)tmp->data)->pipe[1]);
		}
		if (((t_parser *)tmp->data)->bin_path)
			free(((t_parser *)tmp->data)->bin_path);
		ft_free_stab(((t_parser *)tmp->data)->av);
		if (((t_parser *)tmp->data)->redir)
			free_redir(&((t_parser *)tmp->data)->redir);
		free(((t_parser *)tmp->data));
		tmp = tmp->next;
	}
	free_nodes(p, &free);
}

void	free_lexer(t_node **l)
{
	t_node	*tmp;

	tmp = *l;
	while (tmp)
	{
		free(((t_lexer *)tmp->data));
		tmp = tmp->next;
	}
	free_nodes(l, &free);
}

void	ft_flush(t_main *m)
{
	free(m->line);
	free(m->prompt);
	free_env(m->env);
	ft_free_stab(m->paths);
	ft_free_stab(m->builtins);
	ft_free_stab(m->operators);
	rl_clear_history();
}
