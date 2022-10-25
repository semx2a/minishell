/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_flush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:50:50 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/25 23:43:02 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	free_parser(t_node *p)
{
	t_node	*tmp;

	tmp = p;
	while (tmp)
	{	
		ft_free_stab(((t_token *)tmp->data)->av);
		if (((t_token *)tmp->data)->bin_path)
			free(((t_token *)tmp->data)->bin_path);
		if (((t_token *)tmp->data)->file_path)
			free(((t_token *)tmp->data)->file_path);
//		if (((t_token *)tmp->data)->is_redir)
//			close(((t_token *)tmp->data)->fd);
		if (((t_token *)tmp->data)->is_piped)
		{
			close(((t_token *)tmp->data)->pipe[0]);
			close(((t_token *)tmp->data)->pipe[1]);
		}
		tmp = tmp->next;
	}
	free_nodes(&p, &free);
}

void	ft_flush(t_main *m)
{
	free(m->line);
	free(m->prompt);
	free_env(m->env);
	ft_free_stab(m->paths);
	ft_free_stab(m->builtins);
	ft_free_stab(m->operators);
	free(m);
	rl_clear_history();
}
