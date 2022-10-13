/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_jobs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:44:06 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/13 21:26:27 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_process(t_main *m)
{
	m->tokens->pid = fork();
	if (m->tokens->pid == -1)
		ft_error();
	else if (m->tokens->pid > 0)
	{
		waitpid(m->tokens->pid, 0, 0);
		kill(m->tokens->pid, SIGTERM);
	}
	else if (m->tokens->pid == 0)
	{
		if (m->pipe_nb > 0)
		{	
			pipes(m);
			if (m->tokens->id == O_PIPE)
				execute(m);
			else if (m->tokens->id == O_DELEM)
				heredoc(m);
		}
		else
			execute(m);
	}
}

void	job_init(t_main *m)
{
	m->lexicon = xmalloc(sizeof(t_lexer));
	m->lexicon = NULL;
	m->tokens = xmalloc(sizeof(t_parser));
	m->tokens = NULL;
}

void	job(t_main *m)
{
//	job_init(m);
	lexer(m);
	if (m->state != S_OPEN_QUOTE)
		print_lexer(m->lexicon);
/* 	if (!lexer(m) || !parser(m) || !expansion(m))
		return ;
	m->index = 0;
	while (m->tokens)
	{	
		if (is_builtin(m->tokens->av[0], m->builtins) == 1)
			exec_builtin(m);
		else
		{
			ft_process(m);
			m->index++;
		}
		m->tokens = m->tokens->next;

	}
	waitpid(-1, NULL, 0);
	free_parser(m->tokens); */
}
