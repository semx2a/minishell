/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_jobs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:44:06 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/01 21:33:01 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_process(t_main *m, char **envp)
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
		if (is_builtin(m->o.cmds) == 1)
			exit(exec_builtin(m, envp));
		else if (m->o.pipe_nb > 0)
		{	
			pipes(&m->o);
			execute(m, envp);
			ft_close_pipes(&m->o);
		}
		else
			execute(m, envp);
	}
}

// ca va beaucoup changer well shit
void	job(t_main *m, char **envp)
{
//	lexer(m);
//	print_list(m->args);
//	parser();	
	expansion(m);
	while (++m->o.index < m->o.cmd_nb)
		ft_process(m, envp);
	ft_free_parent(&m->o);
	waitpid(-1, NULL, 0);
}
