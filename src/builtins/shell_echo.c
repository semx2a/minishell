/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:12:20 by abonard           #+#    #+#             */
/*   Updated: 2024/02/06 17:15:16 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_flag(char *flags)
{
	int	i;

	i = 0;
	if (flags[i] != '-')
		return (0);
	i++;
	while (flags[i])
	{
		if (flags[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_exec_echo(t_token *t, bool flag)
{
	size_t	i;

	i = 1;
	if (flag == true)
		i = 2;
	while (t->cmds_av[i] && i < t->cmd_ac)
	{
		ft_putstr_fd(t->cmds_av[i], STDOUT_FILENO);
		if (i + 1 < t->cmd_ac)
			ft_putchar_fd(' ', 1);
		else if (i + 1 == t->cmd_ac && flag == true)
			return (0);
		else if (i + 1 == t->cmd_ac && flag == false)
		{
			ft_putchar_fd('\n', 1);
			return (0);
		}
		i++;
	}
	return (-1);
}

int	ft_echo(t_token *t)
{
	bool	flag;

	flag = false;
	if (t->cmd_ac < 2)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		return (0);
	}
	if (ft_is_flag(t->cmds_av[1]) == 1)
		flag = true;
	if (t->cmd_ac == 2 && flag == true)
	{
		g_status = 0;
		return (0);
	}
	else
	{
		if (ft_exec_echo(t, flag) < 0)
		{
			g_status = 1;
			return (-1);
		}
	}
	g_status = 0;
	return (0);
}
