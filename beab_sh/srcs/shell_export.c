/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:02:31 by abonard           #+#    #+#             */
/*   Updated: 2022/10/25 20:57:25 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_export_var(t_main *m, t_token *data, bool is_forked)
{
	char	*namevar;
	char	*value;
	size_t	i;
	size_t	j;

	i = 1;
	while (i < m->cmd_ac)
	{
		j = 0;
		namevar = NULL;
		value = NULL;
		namevar = ft_strdup(data->av[i]);
		while (namevar[j])
		{
			if (namevar[j] == '=')
				namevar[j] = 0;
			else
				j++;
		}
		if (data->av[i][j])
			value = namevar + j + 1;
		ft_check_and_export(namevar, value, m->env, is_forked);
		i++;
	}
	return (0);
}

int	ft_export(t_main *m, t_token *data, bool is_forked)
{
	int	ret;

	ret = 0;
	m->cmd_ac = ft_tablen(data->av);
	if (m->cmd_ac < 2)
	{
		ft_print_declare(m->env, is_forked);
		return (ret);
	}
	ret = ft_export_var(m, data, is_forked);
	return (ret);
}
