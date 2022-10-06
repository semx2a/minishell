/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_jobs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:44:06 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/05 21:05:32 by seozcan          ###   ########.fr       */
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
			execute(m);
			ft_close_pipes(&m->o);
		}
		else
			execute(m);
	}
}

// ca va beaucoup changer well shit
void	job(t_main *m)
{
//	lexer(m);
//	print_list(m->args);
//	parser();	
	expansion(m);
	if (is_builtin(m->o.cmds) == 1)
		exec_builtin(m);
	else
	{
		while (m->o.index < m->o.cmd_nb)
		{
			ft_process(m);
			m->o.index++;
		}
		waitpid(-1, NULL, 0);
	}
	ft_free_parent(&m->o);
	
}
