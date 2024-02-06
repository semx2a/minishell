/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:07:26 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/06 17:15:16 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_path_finder(t_token *t, t_env *env, bool is_forked)
{
	char	*path;

	if (t->cmd_ac < 2)
	{
		path = get_cont("HOME", env);
		if (path == NULL && is_forked)
			ft_putstr_fd("HOME not set\n", STDERR_FILENO);
	}
	else
	{
		if (t->cmds_av[1][0] == '-' && t->cmds_av[1][1] == '\0')
		{
			path = get_cont("OLDPWD", env);
			if (path == NULL && is_forked)
				ft_putstr_fd("OLDPWD not set\n", STDERR_FILENO);
			else if (is_forked)
				printf("%s\n", path);
		}
		else
			path = t->cmds_av[1];
	}
	return (path);
}

void	ft_cd_fail(char *path, int ret, bool is_forked)
{
	if (!is_forked)
		return ;
	if (ret == EACCES)
	{
		ft_putstr_fd("cd: ", STDERR_FILENO);
		ft_putstr_fd(path, STDERR_FILENO);
		ft_putstr_fd(ERR_PERM, STDERR_FILENO);
	}
	if (ret == ENOTDIR)
	{
		ft_putstr_fd("cd: ", STDERR_FILENO);
		ft_putstr_fd(path, STDERR_FILENO);
		ft_putstr_fd(ERR_NODIR, STDERR_FILENO);
	}
	if (ret == ENOENT)
	{
		ft_putstr_fd("cd: ", STDERR_FILENO);
		ft_putstr_fd(path, STDERR_FILENO);
		ft_putstr_fd(ERR_FILE, STDERR_FILENO);
	}
	g_status = 1;
}

int	ft_cd(t_token *t, t_env *env, bool is_forked)
{
	char	*path;
	int		ret;
	char	*oldpath;

	path = ft_path_finder(t, env, is_forked);
	if (path == NULL)
		return (4);
	oldpath = getcwd(NULL, 0);
	if (!oldpath)
		ft_cd_fail(oldpath, errno, is_forked);
	ret = chdir(path);
	if (ret != 0)
		ft_cd_fail(path, errno, is_forked);
	else
	{
		if (oldpath)
			ft_create_o_replace("OLDPWD", oldpath, env);
		path = getcwd(NULL, 0);
		if (path == NULL)
			return (4);
		ft_create_o_replace("PWD", path, env);
		free(path);
	}
	free(oldpath);
	return (ret);
}
