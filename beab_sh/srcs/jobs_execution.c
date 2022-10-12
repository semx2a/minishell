/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:34:43 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/12 17:54:22 by seozcan          ###   ########.fr       */
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
	int		i;
	char	*cmd;
	char	**cmd_and_flags;

	cmd = m->o.tokens->head->arg;
	m->o.tokens->head = m->o.tokens->head->next;
	cmd_and_flags[0] = ft_strdup(cmd);
	i = 1;
	while (m->o.tokens->head->type == (FLAG_ID | ARG_ID))
	{
		cmd_and_flags[i] = ft_strdup(m->o.tokens->head->arg);
		m->o.tokens->head = m->o.tokens->head->next;
		i++;
	}
	m->o.bin_path = get_cmd(m->o.paths, cmd);
	m->o.paths = ft_env_to_tab(m->env);
	if (execve(m->o.bin_path, cmd_and_flags, m->o.paths) != -1)
	{
		free(cmd);
		ft_free_stab(cmd_and_flags);
		ft_free_child(&m->o);
		ft_free_parent(&m->o);
		ft_error();
	}
}

// serach for status code for all the builtin created
int	exec_builtin(t_main *m)
{
	int	ret;

	ret = -1;
	if (ft_strcmp("env", m->o.tokens->head->arg) == 0)
		ret = ft_env(m->env);
	if (ft_strcmp("exit", m->o.tokens->head->arg) == 0)
		ft_exit(m, 1);
	if (ft_strcmp("pwd", m->o.tokens->head->arg) == 0)
		ret = ft_pwd(m->env);
	if (ft_strcmp("cd", m->o.tokens->head->arg) == 0)
		ret = ft_cd(m, 1);
	if (ft_strcmp("echo", m->o.tokens->head->arg) == 0)
		ret = ft_echo(m);
	if (ft_strcmp("export", m->o.tokens->head->arg) == 0)
		ret = ft_export(m, 1);
	if (ft_strcmp("unset", m->o.tokens->head->arg) == 0)
		ret = ft_unset(m, 1);
	return (ret);
}
	// serach for status code for all the builtin created
