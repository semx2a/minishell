/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:12:20 by abonard           #+#    #+#             */
/*   Updated: 2022/10/05 20:52:57 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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

int	ft_exec_echo(t_main *m, bool flag)
{
	int	i;

	i = 1;
	if (flag == true)
		i = 2;
	while (m->o.cmd_flags[i] && i < m->o.cmd_nb)
	{
		ft_putstr_fd(m->o.cmd_flags[i], 1);
		if (i + 1 < m->o.cmd_nb)
			ft_putchar_fd(' ', 1);
		else if (i + 1 == m->o.cmd_nb && flag  == true)
			return (0);
		else if (i + 1 == m->o.cmd_nb && flag == false)
		{
			ft_putchar_fd('\n', 1);
			return (0);
		}
		i++;
	}
	return (-1);
}

int	ft_echo(t_main *m)
{
	bool	flag;

	flag = false;
	m->o.cmd_flags = ft_split(m->o.cmds[0], ' ');
	m->o.cmd_nb = ft_tablen(m->o.cmd_flags);
	if (m->o.cmd_nb < 2)
	{
		ft_putstr_fd("\n", 1);
		return (0);
	}
	if (ft_is_flag(m->o.cmd_flags[1]) == 1)
		flag = true;
	if (m->o.cmd_nb == 2 && flag == true)
		return (0);
	else
	{
		if (ft_exec_echo(m, flag) < 0)
			return (-1);
	}
	return (0);
}