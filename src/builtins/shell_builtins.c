/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:07:26 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/06 17:15:16 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		printf("%s\n", tmp->total);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_pwd(t_env *env)
{
	char	*path;

	path = get_cont("PWD", env);
	if (path == NULL)
	{
		ft_putstr_fd(ERR_VAR, STDERR_FILENO);
		return (1);
	}
	printf("%s\n", path);
	return (0);
}

int	exec_builtin(t_token *t, t_env *env, bool is_forked)
{
	int	ret;

	ret = -1;
	if (ft_strcmplen("env", t->cmds_av[0]) == 0)
		ret = ft_env(env);
	if (ft_strcmplen("exit", t->cmds_av[0]) == 0)
		ret = ft_exit(t, is_forked, env);
	if (ft_strcmplen("pwd", t->cmds_av[0]) == 0)
		ret = ft_pwd(env);
	if (ft_strcmplen("cd", t->cmds_av[0]) == 0)
		ret = ft_cd(t, env, is_forked);
	if (ft_strcmplen("echo", t->cmds_av[0]) == 0)
		ret = ft_echo(t);
	if (ft_strcmplen("export", t->cmds_av[0]) == 0)
		ret = ft_export(t, env, is_forked);
	if (ft_strcmplen("unset", t->cmds_av[0]) == 0)
		ret = ft_unset(t, env, is_forked);
	return (ret);
}

int	is_builtin(char **cmds)
{
	int	ret;

	ret = 0;
	if (ft_strcmp("env", cmds[0]) == 0)
		ret = 1;
	if (ft_strcmp("exit", cmds[0]) == 0)
		ret = 1;
	if (ft_strcmp("pwd", cmds[0]) == 0)
		ret = 1;
	if (ft_strcmp("cd", cmds[0]) == 0)
		ret = 1;
	if (ft_strcmp("echo", cmds[0]) == 0)
		ret = 1;
	if (ft_strcmp("export", cmds[0]) == 0)
		ret = 1;
	if (ft_strcmp("unset", cmds[0]) == 0)
		ret = 1;
	return (ret);
}
