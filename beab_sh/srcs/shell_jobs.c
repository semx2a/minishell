/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_jobs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:44:06 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/14 23:35:15 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_process(t_main *m, t_parser *p)
{
	p->pid = fork();
	if (p->pid == -1)
		ft_error();
	else if (p->pid > 0)
	{
		waitpid(p->pid, 0, 0);
		kill(p->pid, SIGTERM);
	}
	else if (p->pid == 0)
	{
		if (m->pipe_nb > 0)
		{	
			pipes(m);
			if (p->id == O_PIPE)
				execute(m);
			else if (p->id == O_DELEM)
				heredoc(m);
		}
		else
			execute(m);
	}
}

void	job(t_main *m)
{
	if (!lexer(m) || !parser(m))
		return ;
	print_parser(m->tokens);
/* 	if (!lexer(m) || !parser(m) || !expansion(m))
		return ;
	m->index = 0;
	while (m->tokens)
	{	
		if (is_builtin(p->av[0], m->builtins) == 1)
			exec_builtin(m);
		else
		{
			ft_process(m, ((t_parser *)m->tokens->data)->content;
			m->index++;
		}
		m->tokens = p->next;

	}
	waitpid(-1, NULL, 0); */
	free_parser(&m->tokens);
}
