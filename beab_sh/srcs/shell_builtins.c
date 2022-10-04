/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <abonard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:07:26 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/04 19:31:52 by abonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != 0)
	{
		printf("%s\n", envp[i]);
		i++;
	}
	return (0);
}

int	ft_echo(t_main *m)
{
	m->o.cmd_flags = ft_split(m->o.cmds[0], ' ');
	if (m->o.cmd_flags[1] == NULL)
		printf("\n");
	else
		printf("%s\n",  m->o.cmd_flags[1]);
	return (0);
}

int	ft_pwd(char **envp)
{
	char	*path;

	(void)envp;
	path = getenv("PWD");
	if (path == NULL)
	{
		ft_putstr_fd("variable not found\n", 2);
		return (1);
	}
	printf("%s\n", path);
	return (0);
}

int	ft_cd(t_main *m)
{
	m->o.cmd_flags = ft_split(m->o.cmds[0], ' ');
	if (chdir(m->o.cmd_flags[1]) != 0)
	{
		ft_putstr_fd("No such file or directory: No such file or directory\n", 2);
		return (1);
	}
	return (0);
}