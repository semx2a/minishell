/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:34:43 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/06 17:15:16 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_mini_exit(int status, t_token *t, t_env *env)
{
	ft_flush(t);
	free_env(env);
	exit(status);
	return (status);
}

int	ft_exit(t_token *t, bool is_forked, t_env *env)
{
	int	ret;

	ret = 0;
	if (t->cmds_av && t->cmd_ac > 2 && is_forked)
	{
		ft_putstr_fd("exit: too many arguments\n", STDERR_FILENO);
		return (1);
	}
	else if (t->cmds_av && t->cmd_ac >= 2)
	{
		if (ft_strisdigit(t->cmds_av[1]) == 1)
			ret = ft_atoi(t->cmds_av[1]);
		else
		{
			if (is_forked)
				ft_putstr_fd("exit: numeric argument required\n", STDERR_FILENO);
			return (1);
		}
	}
	if (is_forked)
		printf("exit\n");
	ft_flush(t);
	free_env(env);
	exit(ret);
	return (ret);
}
