/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:02:31 by abonard           #+#    #+#             */
/*   Updated: 2024/02/06 17:15:16 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_export_var(t_token *t, t_env *env, bool is_forked, size_t i)
{
	char	*namevar;
	char	*value;
	int		j;

	while (i < t->cmd_ac)
	{
		j = 0;
		namevar = NULL;
		value = NULL;
		namevar = ft_strdup(t->cmds_av[i]);
		while (namevar[j])
		{
			if (namevar[j] == '=')
				namevar[j] = 0;
			else
				j++;
		}
		if (t->cmds_av[i][j])
			value = namevar + j + 1;
		ft_check_and_export(namevar, value, env, is_forked);
		i++;
		free(namevar);
	}
	return (0);
}

int	ft_export(t_token *t, t_env *env, bool is_forked)
{
	int		ret;
	size_t	i;

	i = 1;
	ret = 0;
	if (t->cmd_ac < 2)
	{
		ft_print_declare(env, is_forked);
		return (ret);
	}
	ret = ft_export_var(t, env, is_forked, i);
	return (ret);
}
