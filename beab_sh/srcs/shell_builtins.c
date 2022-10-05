/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <abonard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:07:26 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/04 21:27:54 by abonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_env(t_env *env)
{
	t_env *tmp;

	tmp = env;
	while (tmp)
	{
		printf("%s\n", tmp->total);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_echo(t_main *m)
{
	m->o.cmd_flags = ft_split(m->o.cmds[0], ' ');
	if (m->o.cmd_flags[1] == NULL)
		printf("\n");
	//else if (ft_strcmp(m->o.cmd_flags[1], "$?") == 0)
		//return(ft_lstatcode());
	else
		printf("%s\n",  m->o.cmd_flags[1]);
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