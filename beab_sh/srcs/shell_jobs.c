/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_jobs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:44:06 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/12 17:56:14 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_process(t_main *m)
{
	m->o.pid = fork();
	if (m->o.pid == -1)
		ft_error();
	else if (m->o.pid > 0)
	{
		waitpid(m->o.pid, 0, 0);
		kill(m->o.pid, SIGTERM);
	}
	else if (m->o.pid == 0)
	{
		if (m->o.pipe_nb > 0)
		{	
			pipes(&m->o);
			if (m->o.tokens->head->type == CMD_ID)
				execute(m);
			else if (m->o.tokens->head->type == ID_DELEM)
				heredoc(m);
			ft_close_pipes(&m->o);
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
	m->o.index = 0;
	while (m->o.tokens->head)
	{	
		if (is_builtin(m->o.tokens, m->builtins) == 1)
			exec_builtin(m);
		else
		{
			ft_process(m);
			m->o.index++;
		}
		m->o.tokens->head = m->o.tokens->head->next;

	}
	waitpid(-1, NULL, 0);
	ft_free_parent(&m->o);
}
