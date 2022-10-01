/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:34:43 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/01 18:26:16 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*ret;

	if (access(cmd, 0) == 0)
		return (cmd);
	else
	{
		while (*paths)
		{
			tmp = ft_strjoin(*paths, "/");
			ret = ft_strjoin(tmp, cmd);
			free(tmp);
			if (access(ret, X_OK) == 0)
				return (ret);
			free(ret);
			paths++;
		}
		ft_error();
	}
	return (NULL);
}

void	execute(t_main *m, char **envp)
{
	m->o.cmd_flags = ft_split(m->o.cmds[m->o.index], ' ');
	m->o.cmd = get_cmd(m->o.paths, m->o.cmd_flags[0]);
	if (execve(m->o.cmd, m->o.cmd_flags, envp) != -1)
	{
		ft_free_child(&m->o);
		ft_free_parent(&m->o);
		ft_error();
	}
}

// serach for status code for all the builtin created
int	exec_builtin(t_main *m, char **envp)
{
	int	ret;

	ret = -1;
	if (ft_strcmp("env", m->o.cmds[m->o.index]) == 0)
		ret = ft_env(envp);
	if (ft_strcmp("exit", m->o.cmds[m->o.index]) == 0)
	{
		m->exit = 1;
		ret = 1;
	}
	if (ft_strcmp("pwd", m->o.cmds[m->o.index]) == 0)
		ret = ft_pwd(envp);
	return (ret);
}
	// serach for status code for all the builtin created
