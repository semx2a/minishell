/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:12:20 by abonard           #+#    #+#             */
/*   Updated: 2022/10/25 20:56:12 by seozcan          ###   ########.fr       */
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

int	ft_exec_echo(t_main *m, t_token *data, bool flag)
{
	size_t	i;

	i = 1;
	if (flag == true)
		i = 2;
	while (data->av[i] && i < m->cmd_ac)
	{
		ft_putstr_fd(data->av[i], 1);
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

int	ft_echo(t_main *m, t_token *data)
{
	bool	flag;

	flag = false;
	m->cmd_ac = ft_tablen(data->av);
	if (m->cmd_ac < 2)
	{
		ft_putstr_fd("\n", 1);
		return (0);
	}
	if (ft_is_flag(data->av[1]) == 1)
		flag = true;
	if (m->cmd_ac == 2 && flag == true)
		return (0);
	else
	{
		if (ft_exec_echo(m, data, flag) < 0)
			return (-1);
	}
	return (0);
}
