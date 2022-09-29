/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_jobs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:44:06 by seozcan           #+#    #+#             */
/*   Updated: 2022/09/29 21:07:15 by seozcan          ###   ########.fr       */
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
		if (ft_is_builtin(m->o.cmds) == 1)
			exit(ft_exec_builtin(m, envp));
		if (m->o.pipe_nb > 0)
		{
 			pipes(m->o);
			execute(m, envp);
			ft_close_pipes(&m->o);
		}
		else
			execute(m, envp);
	}
}

// ca va beaucoup changer well shit
void	ft_job(t_main *m, char **envp)
{
	m->o.cmds = ft_split(m->line, ' ');
	ft_process(m, envp);
}
