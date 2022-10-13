/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:34:43 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/13 16:16:30 by seozcan          ###   ########.fr       */
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
		ft_putstr_fd("command not found\n", 2);
	}
	return (NULL);
}

void	execute(t_main *m)
{	
	m->paths = ft_env_to_tab(m->env);
	m->tokens->bin_path = get_cmd(m->paths, m->tokens->av[0]);
	if (execve(m->tokens->bin_path, m->tokens->av, m->paths) != -1)
	{
		ft_free_stab(m->paths);
		free(m->tokens->bin_path);
		ft_error();
	}
}

// serach for status code for all the builtin created
int	exec_builtin(t_main *m)
{
	int	ret;

	ret = -1;
	if (ft_strcmp("env", m->tokens->av[0]) == 0)
		ret = ft_env(m->env);
	if (ft_strcmp("exit", m->tokens->av[0]) == 0)
		ft_exit(m, 1);
	if (ft_strcmp("pwd", m->tokens->av[0]) == 0)
		ret = ft_pwd(m->env);
	if (ft_strcmp("cd", m->tokens->av[0]) == 0)
		ret = ft_cd(m, 1);
	if (ft_strcmp("echo", m->tokens->av[0]) == 0)
		ret = ft_echo(m);
	if (ft_strcmp("export", m->tokens->av[0]) == 0)
		ret = ft_export(m, 1);
	if (ft_strcmp("unset", m->tokens->av[0]) == 0)
		ret = ft_unset(m, 1);
	return (ret);
}
	// serach for status code for all the builtin created
