/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <abonard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:12:20 by abonard           #+#    #+#             */
/*   Updated: 2022/10/12 18:49:11 by abonard          ###   ########.fr       */
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
	while (m->tokens->av[i] && i < m->cmd_ac)
	{
		ft_putstr_fd(m->tokens->av[i], 1);
		if (i + 1 < m->cmd_ac)
			ft_putchar_fd(' ', 1);
		else if (i + 1 == m->cmd_ac && flag == true)
			return (0);
		else if (i + 1 == m->cmd_ac && flag == false)
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
	m->tokens->av = ft_split(m->tokens, ' ');
	m->cmd_ac = ft_tablen(m->tokens->av);
	if (m->cmd_ac < 2)
	{
		ft_putstr_fd("\n", 1);
		return (0);
	}
	if (ft_is_flag(m->tokens->av[1]) == 1)
		flag = true;
	if (m->cmd_ac == 2 && flag == true)
		return (0);
	else
	{
		if (ft_exec_echo(m, flag) < 0)
			return (-1);
	}
	return (0);
}
