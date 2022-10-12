/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_jobs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:44:06 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/12 22:00:09 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_process(t_main *m)
{
	m->tokens->pid = fork();
	if (m->pid == -1)
		ft_error();
	else if (m->pid > 0)
	{
		waitpid(m->pid, 0, 0);
		kill(m->pid, SIGTERM);
	}
	else if (m->pid == 0)
	{
		if (m->pipe_nb > 0)
		{	
			pipes(&m->);
			if (m->tokens->head->type == CMD_ID)
				execute(m);
			else if (m->tokens->head->type == ID_DELEM)
				heredoc(m);
			ft_close_pipes(&m->);
		}
		else
			execute(m);
	}
}

// ca va beaucoup changer well shit
void	job(t_main *m)
{
	if (!lexer(m) || !parser(m) || !expansion(m))
		return ;
	m->index = 0;
	while (m->tokens)
	{	
		if (is_builtin(m->tokens, m->builtins) == 1)
			exec_builtin(m);
		else
		{
			ft_process(m);
			m->index++;
		}
		m->tokens = m->tokens->next;

	}
	waitpid(-1, NULL, 0);
	ft_free_parent(&m->);
}
