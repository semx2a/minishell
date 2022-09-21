/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:07:26 by seozcan           #+#    #+#             */
/*   Updated: 2022/09/21 18:35:13 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_env(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	if (tmp == NULL)
		return (1);
	while (tmp->next != NULL)
	{
		printf("%s\n", tmp->total);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_echo(char **cmds)
{
	(void)cmds;
	return (0);
}

int	ft_pwd(t_env *env)
{
	char	*path;

	path = get_cont("PWD", env);
	if (path == NULL)
	{
		ft_putstr_fd("variable not found\n", 2);
		return (1);
	}
	printf("%s\n", path);
	return (0);
}

int	ft_exit(t_env *env, char **cmds)
{
	(void)env;
	(void)cmds;

	exit(0);
	return (0);
}
