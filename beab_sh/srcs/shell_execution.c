/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:34:43 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/25 20:56:39 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	execute(t_main *m, t_token *data)
{	
	data->bin_path = get_cmd(m->paths, data->av[0]);
	if (execve(data->bin_path, data->av, m->paths) != -1)
	{
		ft_free_stab(m->paths);
		free(data->bin_path);
		ft_error();
	}
}

// serach for status code for all the builtin created
int	exec_builtin(t_main *m, t_token *data)
{
	int	ret;

	ret = -1;
	if (ft_strcmp("env", data->av[0]) == 0)
		ret = ft_env(m->env);
	if (ft_strcmp("exit", data->av[0]) == 0)
		ft_exit(data, 1);
	if (ft_strcmp("pwd", data->av[0]) == 0)
		ret = ft_pwd(m->env);
	if (ft_strcmp("cd", data->av[0]) == 0)
		ret = ft_cd(m, data, 1);
	if (ft_strcmp("echo", data->av[0]) == 0)
		ret = ft_echo(m, data);
	if (ft_strcmp("export", data->av[0]) == 0)
		ret = ft_export(m, data, 1);
	if (ft_strcmp("unset", data->av[0]) == 0)
		ret = ft_unset(m, data, 1);
	return (ret);
}
	// serach for status code for all the builtin created
